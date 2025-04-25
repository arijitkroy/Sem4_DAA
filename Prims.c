#include <stdio.h>
#define INF 99999
int cost[20][20];

int prims(int n) {
    int i, j, k, v1, v2, visited[20], min, minCost = 0;
    for (j = 1; j <= n; j++) visited[j] = 0;
    visited[1] = 1;
    for (k = 1; k < n; k++) {
        min = INF;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] != INF && (visited[i] == 1 && visited[j] == 0) && (cost[i][j] < min)) {
                    min = cost[i][j];
                    v1 = i; v2 = j;
                }
            }
        }
        printf("Edge %d (%d --> %d) [Cost: %d]\n", k, v1, v2, min);
        visited[v1] = visited[v2] = 1;
        minCost += min;
    }
    return minCost;
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
    printf("Minimum Cost: %d", prims(n));
}