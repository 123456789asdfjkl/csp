#include "stdio.h"

int main() {
    int n, m;
    int a[30 + 10][30 + 10] = {0};
    int ans[30 + 10][30 + 10];
    int num_flag[30 + 10][30 + 10] = {0};
    int flag = 1;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == a[i][j + 1]) {
                int num = 2;
                int temp = a[i][j];
                int k;
                for (k = j + 2; k < m; ++k) {
                    if (a[i][k] != temp) {
                        break;
                    } else {
                        num++;
                    }
                }
                if (num >= 3) {
                    for (int l = j; l < k; ++l) {
                        ans[i][l] = 0;
                        num_flag[i][l] = 1;
                    }
                    flag = 0;
                }
            }
            if (a[i][j] == a[i + 1][j]) {
                int num = 2;
                int temp = a[i][j];
                int k;
                for (k = i + 2; k < n; ++k) {
                    if (a[k][j] != temp) {
                        break;
                    } else {
                        num++;
                    }
                }
                if (num >= 3) {
                    for (int l = i; l < k; ++l) {
                        ans[l][j] = 0;
                        num_flag[l][j] = 1;
                    }
                    flag = 0;
                }
            }
            if (flag && num_flag[i][j] == 0) {
                ans[i][j] = a[i][j];
            }
            flag = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d", ans[i][j]);
            if (j < m - 1) {
                printf(" ");
            }
        }
        if (i < n - 1) {
            printf("\n");
        }
    }
    return 0;
}