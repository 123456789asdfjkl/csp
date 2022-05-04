#include "stdio.h"
#include "vector"
#include "algorithm"

struct time {
    int s;
    int e;
};

int main() {
    int n;
    std::vector<time> H, W;
    time temp;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &temp.s, &temp.e);
        H.push_back(temp);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &temp.s, &temp.e);
        W.push_back(temp);
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (H[i].e > W[j].s && H[i].s < W[j].e) {
                sum += std::min(H[i].e, W[j].e) - std::max(H[i].s, W[j].s);
            }
        }
    }
    printf("%d", sum);
    return 0;
}