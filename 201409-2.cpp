#include "stdio.h"

struct rectangle {
    int x1;
    int x2;
    int x3;
    int x4;
};


int main() {
    int n;
    int x1, x2, y1, y2;
    int flag[100 + 10][100 + 10] = {0};
    scanf("%d", &n);
    int count = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for (int j = x1; j < x2; ++j) {
            for (int k = y1; k < y2; ++k) {
                if (flag[j][k] == 0) {
                    count++;
                    flag[j][k] = 1;
                }
            }
        }
    }
    printf("%d",count);
    return 0;
}