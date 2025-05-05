#include <stdio.h>
#define MAX 20
int p[MAX], id[MAX], d[MAX], s[MAX];

void swap(int* a, int* b) {
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

void bubbleSort(int n) {
    int i, j;
    for (i = 1; i <= n - 1; i++) {
        for (j = 1; j <= n - i - 1; j++) {
            if (p[j+1] > p[j]) {
                swap(&p[j], &p[j+1]);
                swap(&id[j], &id[j+1]);
                swap(&d[j], &d[j+1]);
            }
        }
    }
}

int jS(int n) {
    bubbleSort(n);
    int i, c = 0, k, d_max = d[0], total_profit = 0;
    for (i = 1; i < n; i++) if (d[i] > d_max) d_max = d[i];
    for (i = 0; i < d_max; i++) s[i] = -1;
    for (i = 1; i <= n; i++) {
        k = d[i] - 1;
        while (k >= 0) {
            if (s[k] == -1) {
                s[k] = id[i];
                total_profit += p[i];
                c++;
                break;
            }
            k--;
        }
        if (c == d_max) break;
    }
    printf("Slots: |");
    for (i = 0; i < d_max; i++) printf(" %d |", s[i]);
    return total_profit;
}

void main() {
    int i, e;
    printf("No. of Entries: ");
    scanf("%d", &e);
    printf("Enter job id, profit and deadline: ");
    for (i = 1; i <= e; i++) scanf("%d %d %d", &id[i], &p[i], &d[i]);
    printf("\nTotal profit: %d", jS(e));
}
