#include <stdio.h>
#define MAX 20
float p[MAX], w[MAX], r[MAX];

void swap(float* a, float* b) {
    float tmp = *b;
    *b = *a;
    *a = tmp;
}

void bubbleSort(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (r[j+1] > r[j]) {
                swap(&p[j], &p[j+1]);
                swap(&w[j], &w[j+1]);
                swap(&r[j], &r[j+1]);
            }
        }
    }
}

void knapsack(int m, int n) {
    bubbleSort(n);
    float x[n], profit = 0.0;
    int u = m, i;
    for (i = 1; i <= n; i++) x[i] = 0.0;
    for (i = 1; i <= n; i++) {
        if (u < w[i]) break;
        x[i] = 1.0;
        u -= w[i];
    }
    if (i <= n) x[i] = u / w[i];
    printf("x = |");
    for (i = 1; i <= n; i++) profit += x[i] * p[i], printf(" %0.1f |", x[i]);
    printf("\nTotal profit: %0.2f", profit);
}

void main() {
    int i, c, e;
    printf("Enter Knapsack Capacity & No. of Entries: ");
    scanf("%d %d", &c, &e);
    printf("Enter profit and weight: ");
    for (i = 1; i <= e; i++) {
        scanf("%f %f", &p[i], &w[i]);
        r[i] = p[i] / w[i];
    }
    knapsack(c, e);
}