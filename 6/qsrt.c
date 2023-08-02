#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define x 10
#define y 100
#define inc 10

int count = 0;

void quicksort(int *a, int l, int r);
int partition(int *a, int l, int r);
void swap(int *a, int *b);

void main() {
  int i, *a, n;
  FILE *fp1 = fopen("QsrtB.txt", "w");
  FILE *fp2 = fopen("QsrtA.txt", "w");
  FILE *fp3 = fopen("QsrtW.txt", "w");
  srand(time(0));

  for (n = x; n <= y; n += inc) {
    a = (int *)malloc(n * sizeof(int));

    // best case
    a[0] = rand() % 100;
    for (i = 0; i < n; i++)
      a[i] = a[0];

    quicksort(a, 0, n - 1);
    fprintf(fp1, "%d\t%d\t\n", n, count);

    // average case
    for (i = 0; i < n; i++)
      a[i] = rand() % 100;
    count = 0;
    quicksort(a, 0, n - 1);
    fprintf(fp2, "%d\t%d\t\n", n, count);

    // worst case
    a[0] = rand() % 100;
    for (i = 1; i < n; i++)
      a[i] = a[i - 1] + rand() % 100;
    count = 0;
    quicksort(a, 0, n - 1);
    fprintf(fp3, "%d\t%d\t\n", n, count);
  }

  free(a);
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
}

void quicksort(int *a, int l, int r) {
  if (l < r) {
    int s = partition(a, l, r);
    quicksort(a, l, s - 1);
    quicksort(a, s + 1, r);
  }
}

int partition(int *a, int l, int r) {
  int p = a[l], i = l, j = r + 1;
  do {
    do {
      i++;
      count++;
    } while (a[i] < p);
    do {
      j--;
      count++;
    } while (a[j] > p);
    swap(&a[i], &a[j]);
  } while (i < j);
  swap(&a[i], &a[j]);
  swap(&a[l], &a[j]);
  return j;
}

void swap(int *a, int *b) {
  int t;
  t = *a;
  *a = *b;
  *b = t;
}