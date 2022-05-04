#include "stdio.h"

int main() {
    int n;
    int a[1000 + 10];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int ans[1000 + 10];
    for (int i = 1; i < n - 1; ++i) {
        ans[i] = (a[i - 1] + a[i] + a[i + 1]) / 3;
    }
    ans[0] = (a[1] + a[0]) / 2;
    ans[n - 1] = (a[n - 2] + a[n - 1]) / 2;
    for (int i = 0; i < n; ++i) {
        printf("%d", ans[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    return 0;
}