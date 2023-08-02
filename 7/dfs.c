#include <stdio.h>
#include <stdlib.h>

int a[10][10], n, visited[10], acyclic = 1;

// Depth-First Search (DFS) function to traverse the graph starting from vertex
// v
void dfs(int v) {
  int i;
  visited[v] = 1; // Mark the current vertex v as visited
  for (i = 1; i <= n; i++) {
    if (a[v][i] && visited[i]) {
      acyclic = 0; // If there is an edge from v to i and i is already visited,
                   // the graph is cyclic
      printf("%d->%d\n", v,
             i); // Print the edge indicating the presence of a cycle
    }
    if (a[v][i] && !visited[i]) {
      printf("%d-->%d\n", v,
             i); // Print the edge being visited during the DFS traversal
      dfs(i);    // Recursively perform DFS on the unvisited vertex i
    }
  }
}

// Function to determine if the graph is connected and if it is cyclic or
// acyclic
void connectedcyclic() {
  int i = 1;
  while (i <= n) {
    if (!visited[i]) {
      dfs(i); // Perform DFS from an unvisited vertex to explore all components
              // of the graph
      break;  // Break here to avoid infinite loop
    }
    i++; // Move this increment outside the if statement to check all vertices
  }

  // Check if all vertices are visited to determine graph connectivity
  if (i == n + 1)
    printf("Graph is connected\n");
  else
    printf("Graph is disconnected\n");

  // Check the acyclic flag to determine if the graph is cyclic or acyclic
  if (acyclic)
    printf("Graph is acyclic\n");
  else
    printf("Graph is cyclic\n");
}

int main() {
  int i, j, start = 1;
  printf("Enter the number of nodes: ");
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    visited[i] = 0; // Initialize the visited array with all zeros (not visited)

  printf("Enter the adjacency matrix:\n");
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      scanf("%d", &a[i][j]); // Read the adjacency matrix input

  printf("Enter the starting vertex: ");
  scanf("%d", &start);

  dfs(start);        // Perform DFS traversal starting from the specified vertex
  connectedcyclic(); // Determine graph connectivity and cyclic property

  return 0;
}
