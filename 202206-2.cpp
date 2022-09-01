#include "stdio.h"
#include "algorithm"

int main() {
    int n, L, S;
    scanf("%d%d%d", &n, &L, &S);
    std::pair<int, int> a[1000 + 10];
    int B[50 + 10];

    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }

    for (int i = 0; i < S; ++i) {
        for (int j = 0; j < S; ++j) {
            scanf("%d", &B[i][j]);
        }
    }
    
    return 0;
}