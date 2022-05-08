#include "stdio.h"

int main() {
    int n, k, t, x_l, y_d, x_r, y_u;
    int x, y;
    int ans1 = 0, ans2 = 0;
    scanf("%d%d%d%d%d%d%d", &n, &k, &t, &x_l, &y_d, &x_r, &y_u);
    for (int i = 0; i < n; ++i) {
        int flag1 = 1;
        int flag2 = 1;
        int count = 0;
        for (int j = 0; j < t; ++j) {
            scanf("%d%d", &x, &y);
            if (x >= x_l && y >= y_d && x <= x_r && y <= y_u) {
                if (flag1) {
                    ans1++;
                    flag1 = 0;
                }
                count++;
                if (count >= k) {
                    if (flag2) {
                        ans2++;
                        flag2 = 0;
                    }
                }
            } else {
                count = 0;
            }
        }
    }
    printf("%d\n", ans1);
    printf("%d", ans2);
    return 0;
}