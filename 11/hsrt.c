#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int *arr, int n, int i, int *count) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  (*count)++;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest, count);
  }
}

void heapSort(int *arr, int n, int *count) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i, count);

  for (int i = n - 1; i >= 0; i--) {
    swap(&arr[0], &arr[i]);
    heapify(arr, i, 0, count);
  }
}

int main() {
  srand(time(0));

  FILE *b = fopen("b.txt", "w");
  FILE *w = fopen("w.txt", "w");
  FILE *a = fopen("a.txt", "w");

  for (int n = 10; n <= 100; n += 10) {
    int *arr = (int *)malloc(n * sizeof(int));

    // Best Case
    int count = 0;
    for (int i = 0; i < n; i++) {
      arr[i] = 1;
    }
    heapSort(arr, n, &count);
    fprintf(b, "%d\t%d\n", n, count);

    // Worst Case
    count = 0;
    for (int i = 0; i < n; i++) {
      arr[i] = (i == 0) ? rand() % 100 : arr[i - 1] + rand() % 10;
    }
    heapSort(arr, n, &count);
    fprintf(w, "%d\t%d\n", n, count);

    // Average Case
    count = 0;
    int avg_arr[] = {2, 9, 7, 8, 6, 5, 4, 10, 15}; // Initialize array directly
    for (int i = 0; i < n; i++) {
      arr[i] = avg_arr[i]; // Copy values from avg_arr to arr
    }
    heapSort(arr, n, &count);
    fprintf(a, "%d\t%d\n", n, count);

    free(arr);
  }

  fclose(b);
  fclose(w);
  fclose(a);

  return 0;
}