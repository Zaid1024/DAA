#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[20][20], n, visited[20], acyclic = 1, count;
FILE *fp;

void createRandomGraph() {
  int i, j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (i == j)
        a[i][j] = 0;
      else
        a[i][j] = rand() % 2; // Generate random 0 or 1 for the edge presence
    }
  }
}

void dfs(int v) {
  count++;
  int i;
  visited[v] = 1;
  for (i = 1; i <= n; i++) {
    if (a[v][i] && visited[i]) {
      acyclic = 0;
      printf("%d->%d\n", v, i);
    }
    if (a[v][i] && !visited[i]) {
      printf("%d-->%d\n", v, i);
      dfs(i);
    }
  }
}

void connectedcyclic() {
  int i = 1;
  while (i <= n) {
    if (!visited[i]) {
      dfs(i);
      break;
    }
    i++;
  }

  if (i == n + 1)
    printf("Graph is connected\n");
  else
    printf("Graph is disconnected\n");

  if (acyclic)
    printf("Graph is acyclic\n");
  else
    printf("Graph is cyclic\n");

  // Write the count value into the file
  fprintf(fp, "%d\n", count);
}

int main() {
  int i, j, start = 1;
  srand(time(0));
  system("rm dfs_count.txt");
  fp = fopen("dfs_count.txt", "w"); // Open the file for writing

  for (int size = 3; size <= 13; size++) {
    n = size;            // Set the size of the matrix
    createRandomGraph(); // Generate a random graph for the current size

    printf("\nGraph of size %d:\n", n);
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        printf("%d ", a[i][j]); // Print the adjacency matrix for verification
      }
      printf("\n");
    }

    for (i = 1; i <= n; i++)
      visited[i] = 0; // Reset the visited array for each graph

    start = 1; // Reset the starting vertex for each graph
    connectedcyclic();
  }

  fclose(fp); // Close the file

  return 0;
}
