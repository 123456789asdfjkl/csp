#include "stdio.h"

int main(){
    int r, y, g;
    scanf("%d%d%d", &r,&y,&g);
    int n;
    scanf("%d", &n);
    int k, t;
    int time = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &k, &t);
        if (k == 0){
            time += t;
        } else if (k == 1){
            time += t;
        } else if (k == 2){
            time += t + r;
        }
    }
    printf("%d", time);
    return 0;
}