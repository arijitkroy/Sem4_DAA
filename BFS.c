#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int G[MAX][MAX], VISITED[MAX], n, Q[MAX], front = 0, rear = -1;

void ADDQ(int w) {
    Q[++rear] = w;
}

int DELETEQ() {
    return Q[front++];
}

void BFS(int v) {
    int u, w;
    VISITED[v] = 1;
    ADDQ(v);
    while (front <= rear) {
        u = DELETEQ();
        printf("%d ", u);
        for (w = 1; w <= n; w++) {
            if (G[u][w] && !VISITED[w]) {
                ADDQ(w);
                VISITED[w] = 1;
            }
        }
    }
}

void BFT() {
    int i;
    for (i = 1; i <= n; i++) VISITED[i] = 0;
    for (i = 1; i <= n; i++) 
        if (!VISITED[i])
            BFS(i);
}

void main() {
    int edges, i, j, v1, v2;

    printf("Enter number of vertices & edges: ");
    scanf("%d %d", &n, &edges);

    for (i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            G[i][j] = 0;

    printf("Enter edges (v1 v2):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &v1, &v2);
        G[v1][v2] = 1;
        G[v2][v1] = 1;
    }

    printf("Adjacency Matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) printf("%d\t", G[i][j]);
        printf("\n");
    }

    printf("Breadth First Traversal (BFT) of the graph:\n");
    BFT();
}