#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *fp_m, *fp_s, *fp_c;

int gcdm(int m, int n) {
  int r, count = 0;
  while (n != 0) {
    count++;
    r = m % n;
    m = n;
    n = r;
  }
  fprintf(fp_m, "%d\n", count);

  return m;
}

int gcds(int m, int n) {
  int count = 0;
  while (m != n) {
    count++;
    if (m > n)
      m = m - n;
    else
      n = n - m;
  }
  fprintf(fp_s, "%d\n", count);
  return m;
}

int gcdc(int m, int n) {
  int min, count = 0;
  min = (m < n) ? m : n;
  while (min != 1) {
    count++;
    if (m % min == 0)
      if (n % min == 0)
        break;
    min--;
  }
  fprintf(fp_c, "%d\n", count);
  return min;
}

int main() {
  FILE *fp = fopen("GCD.txt", "w+");
  fp_m = fopen("GCDM.txt", "w+");
  fp_s = fopen("GCDS.txt", "w+");
  fp_c = fopen("GCDC.txt", "w+");
  fprintf(fp, "m\tn\tGCDM\tGCDS\tGCDC\n");

  int m, n, min;
  int gm, gs, gc;
  srand(time(0));
  for (int i = 1; i <= 10; i++) {
    m = rand() % 100 + 1;
    n = rand() % 100 + 1;
    min = m > n ? n : m;
    fprintf(fp, "%d\t%d\t", m, n);
    gm = gcdm(m, n);
    gs = gcds(m, n);
    gc = gcdc(m, n);
    fprintf(fp, "%d\t%d\t%d\n", gm, gs, gc);
  }

  fclose(fp);
  fclose(fp_m);
  fclose(fp_s);
  fclose(fp_c);

  return 0;
}
