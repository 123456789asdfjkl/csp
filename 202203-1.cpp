#include "stdio.h"

int main(){
    int n, k;
    int x,y;
    int flag[100000+10]={0};
    flag[0] = 1;
    int count = 0;
    scanf("%d%d",&n, &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d%d",&x, &y);
        if(flag[y] == 0){
            count++;
        }
        flag[x] = 1;
    }
    printf("%d", count);
    return 0;
};