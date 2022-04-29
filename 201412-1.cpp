#include "stdio.h"

int main() {
    int n;
    int a;
    int count[1000 + 10] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        count[a]++;
        printf("%d", count[a]);
        if (i != n - 1) {
            printf(" ");
        }
    }
    return 0;
}