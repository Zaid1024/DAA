#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define x 10
#define y 100
#define inc 10

int count, countb;

void insertionsort(int *a, int n);

int main() {
  int i, n, *a;
  FILE *fp1, *fp2, *fp3;
  fp1 = fopen("IsortB.txt", "w");
  fp2 = fopen("IsortA.txt", "w");
  fp3 = fopen("IsortW.txt", "w");

  for (n = x; n <= y; n += inc) {
    a = (int *)malloc(n * sizeof(int));
    count = 0;

    // Best case: Already sorted array
    for (i = 0; i < n; i++)
      a[i] = i + 1;

    insertionsort(a, n);
    fprintf(fp1, "%d\t%d\n", n, countb);

    // Average case: Randomized array
    count = 0;
    for (i = 0; i < n; i++)
      a[i] = rand() % 100;

    insertionsort(a, n);
    fprintf(fp2, "%d\t%d\n", n, count);

    // Worst case: Reverse sorted array
    count = 0;
    for (i = 0; i < n; i++)
      a[i] = n - i;

    insertionsort(a, n);
    fprintf(fp3, "%d\t%d\n", n, count);

    free(a);
  }

  fclose(fp1);
  fclose(fp2);
  fclose(fp3);

  return 0;
}

void insertionsort(int *a, int n) {
  int i, j, t;
  for (i = 1; i < n; i++) {
    t = a[i];
    j = i - 1;
    countb++;
    while (j >= 0 && a[j] > t) {
      a[j + 1] = a[j];
      count++;
      j--;
    }
    a[j + 1] = t;
  }
}
