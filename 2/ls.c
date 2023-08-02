#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define x 10
#define y 100
#define inc 10

int main() {
  int *a, i, c, n;
  FILE *fp1, *fp2;
  int flag = 0, key;

  srand(time(0)); // Seed the random number generator based on the current time

  system("rm ls_w.txt");   // Remove the existing ls_b.txt file
  system("rm ls_w_c.txt"); // Remove the existing ls_b_c.txt file

  fp1 = fopen("ls_w.txt", "a"); // Open the file ls_b.txt in "a" mode (append)

  for (n = x; n <= y; n += inc) {
    a = (int *)malloc(n * sizeof(int)); // Dynamically allocate memory for an
                                        // integer array a of size n
    for (i = 0; i < n; i++) {
      a[i] = rand() %
             100; // Generate random integers and store them in the array a
    }

    key = a[n]; // Store the first element of the array a as the key to search for

    c = 0; // Initialize the count variable to zero

    // Loop to search for the key in the array a
    for (i = 0; i < n; i++) {
      c++; // Increment the count for each iteration of the loop
      if (a[i] == key) {
        flag = 1; // Set the flag to 1 if the key is found in the array
        break;    // Break out of the loop as we found the key
      }
    }

    // Write the elements of the array a to the file ls_b.txt for this iteration
    fprintf(fp1, "iteration:");
    for (i = 0; i < n; i++) {
      fprintf(fp1, "%d\t", a[i]);
    }

    // Open the file ls_b_c.txt in "a" mode (append) to store the count data
    fp2 = fopen("ls_w_c.txt", "a");
    fprintf(fp2, "%d\t", n); // Write the value of n (the current array size)
    fprintf(fp2, "%d\n", c); // Write the count value to the file ls_b_c.txt
    fclose(fp2);             // Close the file ls_b_c.txt after writing the data

    free(a); // Free the memory allocated for the array a to avoid memory leaks
  }

  fclose(fp1); // Close the file ls_b.txt

  return 0;
}
