/*
 * 差分前缀和
 */
#include "stdio.h"
#include "algorithm"

using namespace std;

int main() {
    int n, m, k, t, c, q, d[200001] = {0};
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &t, &c);
        d[max(0, t - k - c + 1)]++;
        d[max(0, t - k + 1)]--;
    }
    for (int i = 1; i <= 200000; i++)
        d[i] += d[i - 1];
    for (int i = 1; i <= m; i++) {
        scanf("%d", &q);
        printf("%d\n", d[q]);
    }
    return 0;
}