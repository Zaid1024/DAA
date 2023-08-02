#include <stdio.h>
#include <stdlib.h>
#define x 10
#define y 100
#define inc 10

int count;

int sort(int a[], int n) {
  int swapped = 0;
  count = 0;
  int i, j, temp;
  for (i = 0; i < n - 1; i++) {
    swapped = 0;
    for (j = 0; j < n - i - 1; j++) {
      count++;
      if (a[j] > a[j + 1]) {
        swapped = 1;
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
    if (!swapped) {
      return 0;
    }
  }
  return 1;
}

int main() {
  FILE *fp1, *fp2, *fp3;
  int n;
  int a[y];
  system("rm bs_best.txt");
  system("rm bs_worst.txt");
  system("rm bs_avg.txt");
  fp1 = fopen("bs_best.txt", "w");
  fp2 = fopen("bs_worst.txt", "w");
  fp3 = fopen("bs_avg.txt", "w");

  srand(time(0));
  int i;
  for (n = x; n <= y; n += inc) {
    count = 0;
    for (i = 0; i < n; i++) {
      a[i] = i + 1;
    }
    sort(a, n);
    fprintf(fp1, "%d\t%d\n", n, count);

    for (i = 0; i < n; i++) {
      a[i] = n - i; // Corrected the initialization for the worst case scenario
    }

    count = 0;
    sort(a, n);
    fprintf(fp2, "%d\t%d\n", n, count);

    for (i = 0; i < n; i++) {
      a[i] = rand() % 100;
    }

    count = 0;
    sort(a, n);
    fprintf(fp3, "%d\t%d\n", n, count);
  }

  fclose(fp1);
  fclose(fp2);
  fclose(fp3);

  return 0;
}