#include "stdio.h"
#include "algorithm"

int main() {
    int n, L, r, t;
    int a[600 + 10][600 + 10] = {0};
    scanf("%d%d%d%d", &n, &L, &r, &t);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    int sum[600 + 10][600 + 10];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + a[i][j] - sum[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x1, y1, x2, y2;
            x1 = std::max(1, i - r);
            y1 = std::max(1, j - r);
            x2 = std::min(n, i + r);
            y2 = std::min(n, j + r);
            if ((sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1]) * 1.0 /
                ((x2 - x1 + 1) * (y2 - y1 + 1)) <= t) {
                ans++;
            }
        }
    }
    printf("%d", ans);
    return 0;
}