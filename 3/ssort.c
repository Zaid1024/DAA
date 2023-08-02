#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define x 10
#define y 100
#define inc 10

FILE *fp1, *fp2;

void sort(int *a, int n) {
  int i, j, min, t, count = 0;
  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
      count++;
      if (a[j] < a[min])
        min = j;
    }
    t = a[i];
    a[i] = a[min];
    a[min] = t;
  }
  fprintf(fp2, "%d\t%d\n", n, count);
}

int main() {
  int *a, n, i;
  fp1 = fopen("ssort.txt", "w");
  fp2 = fopen("ssort_count.txt", "w");
  srand(time(0));
  for (n = x; n <= y; n += inc) {
    a = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
      a[i] = rand() % 100;
      fprintf(fp1, "%d\t", a[i]);
    }
    fprintf(fp1, "\n"); // Add a new line after writing the elements for each size
    fprintf(fp2, "%d\t", n); // Move this line here to record size before sorting
    sort(a, n);
    free(a); // Free the dynamically allocated memory
  }
  fclose(fp1);
  fclose(fp2);

  return 0;
}