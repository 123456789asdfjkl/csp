#include "stdio.h"
#include "algorithm"

int main() {
    int n;
    int a[1000 + 10];
    int count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n);
    for (int i = 1; i < n; ++i) {
        if (a[i] - a[i - 1] == 1) {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}