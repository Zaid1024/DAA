#include <stdio.h>

int cost[40][40], n, visited[40] = {0}, c;

void createGraph() {
  printf("No. of vertices>> ");
  scanf("%d", &n);
  printf("Enter cost matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &cost[i][j]);
    }
  }
}

void main() {
  int i, j, edges = 0;
  int a, b, min, min_cost = 0;

  createGraph();

  visited[0] = 1;
  while (edges < n - 1) {
    min = 9999;
	//	c++;
    for (i = 0; i < n; i++) {
      if (visited[i]) {
    c++;
				for (j = 0; j < n; j++) {
        //  c++;
          if (cost[i][j] && min > cost[i][j] && !visited[j]) {
            min = cost[i][j];
            a = i;
            b = j;
          }
        }
      }
    }

    printf("%d-->%d | Cost: %d\n", a, b, min);
    visited[b] = 1;
    min_cost += min;
    edges++;
  }

  printf("Minimum Cost: %d\nand count = %d", min_cost, c);
}