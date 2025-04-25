#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int G[MAX][MAX], VISITED[MAX], n;

void DFS(int v) {
    VISITED[v] = 1;
    printf("%d ", v);
    for (int w = 1; w <= n; w++) 
        if (G[v][w] && !VISITED[w])
            DFS(w);
}

void main() {
    int i, j, v1, v2, start;
    printf("Enter the number of vertices & starting vertex: ");
    scanf("%d %d", &n, &start);
    for (i = 1; i <= n; i++) VISITED[i] = 0;
    printf("Adjacency Matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) 
			scanf("%d", &G[i][j]);

    printf("DFS traversal starting from vertex %d:\n", start);
    DFS(start);
}
