#include "stdio.h"

int main() {
    int T;
    scanf("%d", &T);
    int ans;
    if (T <= 3500) {
        ans = T;
    } else if (T <= 4955) {
        ans = 3500 + (T - 3500) / (1 - 0.03);
    } else if (T <= 7655) {
        ans = 3500 + 1500 + (T - 4955) / (1 - 0.1);
    } else if (T <= 11255) {
        ans = 3500 + 4500 + (T - 7655) / (1 - 0.2);
    } else if (T <= 30755) {
        ans = 3500 + 9000 + (T - 11255) / (1 - 0.25);
    } else if (T <= 44755) {
        ans = 3500 + 35000 + (T - 30755) / (1 - 0.3);
    } else if (T <= 61005) {
        ans = 3500 + 55000 + (T - 44755) / (1 - 0.35);
    } else {
        ans = 3500 + 80000 + (T - 61005) / (1 - 0.45);
    }
    printf("%d", ans);
    return 0;
}