#include "stdio.h"
#include "map"

int main() {
    std::map<int, int> mpa;
    int n, a, b;
    int index, value;
    long long int ans = 0;
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i < a; ++i) {
        scanf("%d%d", &index, &value);
        mpa[index] = value;
    }
    std::map<int, int>::iterator it;
    for (int i = 0; i < b; ++i) {
        scanf("%d%d", &index, &value);
        if (mpa.find(index) != mpa.end()) {
            ans += mpa[index] * value;
        }
    }
    printf("%lld", ans);
}