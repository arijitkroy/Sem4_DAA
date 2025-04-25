#include <stdio.h>
#define INF 999999
int cost[20][20], A[20][20];

int min(int a, int b) {
    return a < b ? a : b;
}
 
void allPairs(int n) {
    int i, j, k;
    for (i = 1; i <= n; i++) 
        for (j = 1; j <= n; j++)
            A[i][j] = cost[i][j];
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
}

void showPaths(int n) {
    int i, j;
    printf("V1\tV2\tEdge\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) 
            if (i != j) printf("%d\t%d\t%d\n", i, j, A[i][j]);
}

void main() {
    int n, i, j;
    printf("Total vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        cost[i][i] = 0;
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j) cost[i][j] = INF;
        }
    }
    allPairs(n);
    showPaths(n);
}