#include <stdio.h>
#include <stdlib.h>

struct Item {
    int weight, value; // weight and value of the item
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Recursive function with memoization to solve the Knapsack problem
int knapsackUtil(int capacity, const struct Item items[], int n, int** memo) {
    if (n == 0 || capacity == 0) {
        return 0;
    }

    // If the value is already calculated, return it from the memo table
    if (memo[n][capacity] != -1) {
        return memo[n][capacity];
    }

    // If the weight of the nth item is more than the knapsack capacity, exclude it
    if (items[n - 1].weight > capacity) {
        memo[n][capacity] = knapsackUtil(capacity, items, n - 1, memo);
    } else {
        // Calculate the maximum value by either including or excluding the nth item
        memo[n][capacity] = max(items[n - 1].value + knapsackUtil(capacity - items[n - 1].weight, items, n - 1, memo),
                                knapsackUtil(capacity, items, n - 1, memo));
    }

    return memo[n][capacity];
}

// Function to solve the Knapsack problem using dynamic programming with memoization
int knapsack(int capacity, const struct Item items[], int n) {
    // Create a memo table to store the calculated values to avoid redundant calculations
    int** memo = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        memo[i] = (int*)malloc((capacity + 1) * sizeof(int));
        for (int j = 0; j <= capacity; j++) {
            memo[i][j] = -1; // Initialize the memo table with -1
        }
    }

    int result = knapsackUtil(capacity, items, n, memo);

    // Free the memory used for the memo table
    for (int i = 0; i <= n; i++) {
        free(memo[i]);
    }
    free(memo);

    return result;
}

int main() {
    int capacity, n;
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    printf("Enter weight and value for each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    printf("Maximum value that can be achieved: %d\n", knapsack(capacity, items, n));

    return 0;
}
