#include "stdio.h"

int main() {
    int n;
    int a;
    int count = 0;
    int flag[2000 + 10] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        flag[a + 1000]++;
        if (flag[1000 - a] != 0) {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}