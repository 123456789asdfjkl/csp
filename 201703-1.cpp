#include "stdio.h"

int main(){
    int n, k, a;
    scanf("%d%d", &n, &k);
    int sum = 0;
    int temp = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        temp +=a;
        if (temp >= k){
            sum++;
            temp = 0;
        }
    }
    if (temp != 0){
        sum++;
    }
    printf("%d", sum);
    return 0;
}