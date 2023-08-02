#include <stdio.h>
#include <stdlib.h>

struct Item {
    int w, v; // weight, value
};

int mx(int a, int b) {
    return (a > b) ? a : b;
}

int k(int c, const struct Item it[], int n, int** m) {
    if (n == 0 || c == 0) {
        return 0;
    }

    if (m[n][c] != -1) {
        return m[n][c];
    }

    if (it[n - 1].w > c) {
        m[n][c] = k(c, it, n - 1, m);
    } else {
        m[n][c] = mx(it[n - 1].v + k(c - it[n - 1].w, it, n - 1, m), k(c, it, n - 1, m));
    }

    return m[n][c];
}

int knapsack(int c, const struct Item it[], int n) {
    int** m = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        m[i] = (int*)malloc((c + 1) * sizeof(int));
        for (int j = 0; j <= c; j++) {
            m[i][j] = -1;
        }
    }

    int r = k(c, it, n, m);

    for (int i = 0; i <= n; i++) {
        free(m[i]);
    }
    free(m);

    return r;
}

int main() {
    int c, n;
    printf("Enter knapsack capacity: ");
    scanf("%d", &c);

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item it[n];
    printf("Enter weight and value for each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &it[i].w, &it[i].v);
    }

    printf("Maximum value that can be achieved: %d\n", knapsack(c, it, n));

    return 0;
}
