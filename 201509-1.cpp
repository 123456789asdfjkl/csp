#include "stdio.h"

int main() {
    int n;
    scanf("%d", &n);
    int a1, a2;
    scanf("%d", &a1);
    int count = 1;
    for (int i = 1; i < n; ++i) {
        scanf("%d", &a2);
        if (a1 != a2) {
            count++;
        }
        a1 = a2;
    }
    printf("%d", count);
    return 0;
}