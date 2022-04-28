//
// Created by changjunlin on 2022/3/22
//
#include "stdio.h"
#define MAX 100+10

int main(){
    int n;
    int b[MAX];
    int max_sum = 0;
    int min_sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &b[i]);
        max_sum += b[i];
        if (i == 0){
            min_sum += b[i];
        }
        if(b[i] > b[i - 1] && i != 0){
            min_sum += b[i];
        }
    }
    printf("%d\n%d", max_sum, min_sum);
    return 0;
}

