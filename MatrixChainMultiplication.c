#include <stdio.h>
#define INF 99999
int d, p[20], m[20][20], s[20][20];

int MCO() {
    int i, j, k, l, q, n = d - 1;
    for (i = 1; i <= n; i++) m[i][i] = 0;
    for (l = 2; l <= n; l++) {
        for (i = 1; i <= n - l + 1; i++) {
            j = i + l - 1;
            m[i][j] = INF;
            for (k = i; k < j; k++) {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("M-Table:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) printf("0\t");
            else if (i < j) printf("%d\t", m[i][j]);
            else printf(" \t");
        }
        printf("\n");
    }
    printf("S-Table:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) printf("x\t");
            else if (i < j) printf("%d\t", s[i][j]);
            else printf(" \t");
        }
        printf("\n");
    }
    return m[1][n];
}

void POP(int i, int j) {
    if (i == j) printf("A%d", i);
    else {
        printf("(");
        POP(i, s[i][j]);
        POP(s[i][j]+1, j);
        printf(")");
    }
}

void main() {
    int i;
    printf("No. of Dimensions: ");
    scanf("%d", &d);
    printf("Enter dimensions: ");
    for (i = 0; i < d; i++) scanf("%d", &p[i]);
    printf("Minimal Cost: %d", MCO());
    printf("\nParenthesis Form: ");
    POP(1, d - 1);
}
