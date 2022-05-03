#include "stdio.h"

int main() {
    int n;
    int a[500 + 10][500 + 10];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    int x = 0, y = 0;
    int flag = 1;
    int state_flag = 1;
    for (int i = 0; i < n * n; ++i) {
        printf("%d", a[x][y]);
        if (i < n * n - 1) {
            printf(" ");
        }
        if (state_flag == 1) {
            if (x == 0) {
                if (y == n - 1) {
                    x++;
                } else {
                    y++;
                }
                flag = 1;
                state_flag = 0;
                continue;
            }
            if (y == 0) {
                if (x == n - 1) {
                    y++;
                } else {
                    x++;
                }
                flag = 0;
                state_flag = 0;
                continue;
            }
            if (y == n - 1) {
                x++;
                flag = 1;
                state_flag = 0;
                continue;
            }
            if (x == n - 1) {
                y++;
                flag = 0;
                state_flag = 0;
                continue;
            }
        }
        if (flag) {
            x++;
            y--;
        } else {
            x--;
            y++;
        }
        state_flag = 1;
    }
    return 0;
}