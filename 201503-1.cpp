#include "stdio.h"

int main() {
    int n, m;
    int a[1000 + 10][1000 + 10];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int j = m - 1; j >= 0; --j) {
        for (int i = 0; i < n; ++i) {
            printf("%d", a[i][j]);
            if (i != n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}