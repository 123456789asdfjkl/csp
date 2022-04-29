#include "stdio.h"

int main() {
    int n;
    int a[1000 + 10];
    int count = 0;
    scanf("%d", &n);
    scanf("%d", &a[0]);
    scanf("%d", &a[1]);
    for (int i = 2; i < n; ++i) {
        scanf("%d", &a[i]);
        if ((a[i - 2] < a[i - 1] && a[i - 1] > a[i]) || (a[i - 2] > a[i - 1] && a[i - 1] < a[i])) {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}