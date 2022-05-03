#include "stdio.h"
#include "algorithm"

struct array {
    int number;
    int count = 0;
};

int cmp(array a, array b) {
    if (a.count < b.count) {
        return 0;
    }
    if (a.count == b.count && a.number > b.number) {
        return 0;
    }
    return 1;
}

int main() {
    int n;
    int a;
    int flag[1000 + 10] = {0};
    scanf("%d", &n);
    array num[1000 + 10];
    int count = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        num[a].count++;
        num[a].number = a;
        if (flag[a] == 0) {
            count++;
            flag[a] = 1;
        }
    }
    std::sort(num, num + 1000 + 10, cmp);
    for (int i = 0; i < count - 1; ++i) {
        printf("%d %d\n", num[i].number, num[i].count);
    }
    printf("%d %d", num[count - 1].number, num[count - 1].count);
    return 0;
}