#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int queue[MAX], front = -1, rear = -1;

void enqueue(int node) {
  if (front == -1)
    front = 0;
  queue[++rear] = node;
}

int dequeue() {
  int item = queue[front++];
  if (front > rear)
    front = rear = -1;
  return item;
}

int isEmpty() {
  if (front == -1 || front > rear)
    return 1;
  else
    return 0;
}

int main() {
  int n, cyclic = 0, sum = 0, connected = 0;
  int i;
  printf("Enter the number of vertices: ");
  scanf("%d", &n);
  int graph[n][n];
  printf("Enter the matrix:\n");
  for (i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("graph[%d][%d]: ", i, j);
      scanf("%d", &graph[i][j]);
    }
  }
  int visited[n];
  for (i = 0; i < n; i++)
    visited[i] = 0;

  printf("BFS traversal:\n");

  for (i = 0; i < n; i++) {
    if (!visited[i]) {
      int count = 0;
      enqueue(i);
      visited[i] = 1;
      while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);
        count++;

        for (int j = 0; j < n; j++) {
          if (graph[current][j]) {
            if (!visited[j]) {
              enqueue(j);
              visited[j] = 1;
            } else if (visited[j] && j != current) {
              cyclic = 1;
            }
          }
        }
      }
      if (count == n)
        connected = 1;
    }
  }
  printf("\n");
  if (connected)
    printf("Graph is connected.\n");
  else
    printf("Graph is disconnected.\n");
  if (cyclic)
    printf("Graph is cyclic.\n");
  else
    printf("Graph is acyclic.\n");
  return 0;
}