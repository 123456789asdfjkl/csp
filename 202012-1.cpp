#include "stdio.h"

int main(){
    int n;
    int w;
    int score;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &w, &score);
        sum += w * score;
    }
    if (sum > 0){
        printf("%d", sum);
    } else{
        printf("0");
    }
    return 0;
}