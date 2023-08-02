// topological source
#include <stdio.h>
#include <stdlib.h>

void main() {
  int n;
  printf("Enter the number of vertices: ");
  scanf("%d", &n);

  int graph[n][n];

  printf("Enter the adjacency matrix of the DAG:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // printf("[%d] -> [%d]", i, j);
      scanf("%d", &graph[i][j]);
    }
  }

  int *vis = (int *)calloc(n, sizeof(int));
  int *indeg = (int *)calloc(n, sizeof(int));

  // Calculate in-degrees of each vertex
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      indeg[i] += graph[j][i];
    }
  }

  printf("Topological sorting: \n");
  int count;
  int c = 0; // Counter to track comparisons

  // Perform Topological Sorting
  for (count = 0; count < n; count++) {
    int found = 0;

    for (int i = 0; i < n; i++) {
      // If a vertex with in-degree 0 and not visited is found
      if (indeg[i] == 0 && vis[i] == 0) {
        printf("%d ", i);
        vis[i] = 1;

        // Reduce in-degrees of adjacent vertices
        for (int j = 0; j < n; j++) {
          if (graph[i][j] == 1) {
            indeg[j]--;
            c++; // Increment comparison counter
          }
        }
        found = 1;
        break;
      }
      c++; // Increment comparison counter for the comparison of the if
           // condition
    }

    // If no vertex with in-degree 0 is found, the graph is not a DAG
    if (!found) {
      printf("\nError: Graph is not a Directed Acyclic Graph (DAG).\n");
      break;
    }
  }

  // If the loop completed without the error condition, the graph is a DAG
  if (count == n) {
    printf("\nGraph is a Directed Acyclic Graph (DAG).\n");
  }

  // Write the number of comparisons to a text file
  FILE *fp = fopen("comparison_count.txt", "a");
  if (fp) {
    fprintf(fp, "%d\t%d\n", n, c);
    fclose(fp);
  } else {
    printf("Error writing to file.\n");
  }

  free(vis);
  free(indeg);
}