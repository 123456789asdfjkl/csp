#include "stdio.h"

int main(){
    int n, X, Y;
    scanf("%d%d%d", &n, &X, &Y);
    int x, y;
    long long int dis[3] = {0x3f3f3f3f, 0x3f3f3f3f,0x3f3f3f3f};
    int ind[3] = {0, 1, 2};
    int distance;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x, &y);
        int x_ = X - x;
        int y_ = Y - y;
        distance = x_ * x_ + y_ * y_;
        for (int j = 0; j < 3; ++j) {
            if (distance < dis[j]){
                for (int k = 2; k > j; k--) {
                    dis[k] = dis[k - 1];
                    ind[k] = ind[k - 1];
                }
                dis[j] = distance;
                ind[j] = i;
                break;
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        printf("%d\n", ind[i] + 1);
    }
    return 0;
}