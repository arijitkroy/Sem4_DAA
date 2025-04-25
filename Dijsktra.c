#include <stdio.h>
#define INF 99999
#define SIZE 20
int dist[SIZE], cost[SIZE][SIZE], pred[SIZE];

void dijkstra(int n, int v) {
    int i, u, w, min, count, status[n];
    pred[v] = -1;
    for (i = 1; i <= n; i++) {
        status[i] = 0;
        dist[i] = INF;
    }
    dist[v] = 0;
    for (count = 2; count <= n; count++) {
        min = INF;
        for (w = 1; w <= n; w++) {
            if (dist[w] < min && status[w] == 0) min = dist[w], u = w;
        }
        status[u] = 1;
        for (w = 1; w <= n; w++) {
            if ((dist[u] + cost[u][w] < dist[w]) && (status[w] != 1)) dist[w] = dist[u] + cost[u][w], pred[w] = u;
        }
    }
}

void path(int n, int v) {
    int i;
    for (i = 1; i <= n; i++) if (i != v) printf("%d --> %d = %d (Predecesor: %d)\n", v, i, dist[i], pred[i]);
}

void main() {
    int n, i, j, src;
    printf("Number of Vertices & Source Vertex: ");
    scanf("%d %d", &n, &src);
    printf("Enter cost Matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) cost[i][j] = INF;
        }
    }
    dijkstra(n, src);
    path(n, src);
}