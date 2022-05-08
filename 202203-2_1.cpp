/*
 * 70
 */
#include "stdio.h"

struct thing {
    int t;
    int c;
};

int main() {
    int n, m, k;
    thing th[100000 + 10];
    int q;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &th[i].t, &th[i].c);
    }
    for (int i = 0; i < m; ++i) {
        int count = 0;
        scanf("%d", &q);
        int temp = q + k;
        for (int j = 0; j < n; ++j) {
            if (temp <= th[j].t && th[j].t <= q + k + th[j].c - 1) {
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}