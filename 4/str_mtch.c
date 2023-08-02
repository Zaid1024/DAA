#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define x 10
#define y 100
#define inc 10

void match(char *a, int n, char *p, int m, FILE *fp) {
  int i, j, count = 0;
  for (i = 0; i < n - m; i++) {
    j = 0;
    while (j < m && p[j] == a[i + j]) {
      j++;
      count++;
    }
    if (j == m)
      break;
  }
  fprintf(fp, "%d\t", count);
}

int main() {
  int i, n, count, w;
  char *a, p[4];
  FILE *fp_best, *fp_avg, *fp_worst;
  fp_best = fopen("best.txt", "w");
  fp_avg = fopen("avg.txt", "w");
  fp_worst = fopen("worst.txt", "w");

  for (n = x; n <= y; n += inc) {
    a = (char *)malloc(n * sizeof(char));
    for (i = 0; i < n; i++)
      a[i] = 'a';

    // best case
    strcpy(p, "aaa");
    match(a, n, p, 3, fp_best);

    // avg case
    strcpy(p, "aba");
    match(a, n, p, 3, fp_avg);

    // worst case
    strcpy(p, "aab");
    match(a, n, p, 3, fp_worst);

    fprintf(fp_best, "\n");
    fprintf(fp_avg, "\n");
    fprintf(fp_worst, "\n");
    free(a);
  }

  fclose(fp_best);
  fclose(fp_avg);
  fclose(fp_worst);

  return 0;
}
