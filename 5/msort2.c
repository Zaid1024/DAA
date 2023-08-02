#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define x 10
#define y 100
#define inc 10

int count;

void copy(int *a, int l, int r, int *b);
void merge(int *b, int n1, int *c, int *a, int n2);
void mergesort(int *a, int n);
void join(int arr[], int left[], int right[], int l, int m, int r);
void split(int arr[], int left[], int right[], int l, int m, int r);
void genworstarr(int arr[], int l, int r);

int main() {
  int *a, n, i;
  FILE *fp = fopen("msortcount.txt", "w");
  srand(time(0));
  for (n = x; n <= y; n += inc) {
    a = (int *)malloc(n * sizeof(int));

    // Best case
    a[0] = rand() % 100;
    for (i = 1; i < n; i++) {
      a[i] = a[i - 1] + rand() % 100;
      count = 0;
      mergesort(a, n);
      fprintf(fp, "%d\t%d\t", n, count);
    }

    // Average case
    for (i = 0; i < n; i++) {
      a[i] = rand() % 100;
      count = 0;
      mergesort(a, n);
      fprintf(fp, "%d\t%d\t", n, count);
    }

    // Worst case
    a[0] = rand() % 100;
    for (i = 1; i < n; i++) {
      a[i] = a[i - 1] + rand() % 100;
    }
    genworstarr(a, 0, n - 1);
    count = 0;
    mergesort(a, n);
    fprintf(fp, "%d\t%d\t", n, count);

    free(a);
  }
  fclose(fp);

  return 0;
}

void copy(int *a, int l, int r, int *b) {
  int i = l;
  int j = 0;
  while (i <= r && j < r - l + 1)
    b[j++] = a[i++];
}

void merge(int *b, int n1, int *c, int *a, int n2) {
  int i = 0, j = 0, k = 0;
  while (i < n1 && j < n2) {
    count++;
    if (b[i] <= c[j])
      a[k] = b[i++];
    else
      a[k] = c[j++];
    k++;
  }
  if (j == n2)
    while (i < n1)
      a[k++] = b[i++];
  else
    while (j < n2)
      a[k++] = c[j++];
}

void mergesort(int *a, int n) {
  if (n > 1) {
    int n1 = n / 2;
    int n2 = (n + 1) / 2;
    int *b = (int *)malloc(n1 * sizeof(int));
    int *c = (int *)malloc(n2 * sizeof(int));
    copy(a, 0, n1 - 1, b);
    copy(a, n1, n - 1, c);
    mergesort(b, n1);
    mergesort(c, n2);
    merge(b, n1, c, a, n2);
    free(b);
    free(c);
  }
}

void join(int arr[], int left[], int right[], int l, int m, int r) {
  int i, j;
  for (i = 0; i < m - l + 1; i++)
    arr[i] = left[i];
  for (j = 0; j < r - m; j++)
    arr[i + j] = right[j];
}

void split(int arr[], int left[], int right[], int l, int m, int r) {
  int i, j;
  for (i = 0; i < m - l + 1; i++)
    left[i] = arr[i * 2];
  for (j = 0; j < r - m; j++)
    right[j] = arr[j * 2 + 1];
}

void genworstarr(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r + 1) / 2;
    int left[m - l + 1];
    int right[r - m];
    split(arr, left, right, l, m, r);
    genworstarr(left, l, m);
    genworstarr(right, m + 1, r);
    join(arr, left, right, l, m, r);
  }
}