#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ini 10  // initial
#define fin 100 // final
#define ste 10  // steps
int c = 0;
void writeCount(int n, FILE *fp) {
  fprintf(fp, "%d\t%d\n", n, c);
  c = 0;
}
void bSearch(int *a, int s, int e, int key) {
  int m = (s + e) / 2; // s=start e=end
  c++;
  if (a[m] == key)
    return;
  else {
    if (s >= e)
      return;
    else if (key > a[m])
      bSearch(a, m + 1, e, key);
    else
      bSearch(a, s, m - 1, key);
  }
}
void main() {
  int *a;
  FILE *f = fopen("BSarrayInfo.txt", "w");
  FILE *fB = fopen("BSBest.txt", "w");
  FILE *fA = fopen("BSAvg.txt", "w");
  FILE *fW = fopen("BSWorst.txt", "w");
  srand(time(0));
  for (int n = ini; n <= fin; n += ste) {
    a = (int *)malloc(n * sizeof(int));
    fprintf(f, "Array : \n");
    for (int i = 0; i < n; i++) {
      a[i] = (rand() + 1) % 100;
      fprintf(f, "%d\t", a[i]);
    }
    fprintf(f, "\nBest Search : %d\tAverage Search : %d\tWorst Search : 9999\n",
            a[n / 2], a[n / 2 + n / 4]);
    bSearch(a, 0, n - 1, a[(n - 1) / 2]);
    writeCount(n, fB);
    bSearch(a, 0, n - 1, a[3 * (n - 1) / 4]);
    writeCount(n, fA);
    bSearch(a, 0, n - 1, 9999);
    writeCount(n, fW);
  }
  fclose(f);
  fclose(fB);
  fclose(fW);
  fclose(fA);
}
