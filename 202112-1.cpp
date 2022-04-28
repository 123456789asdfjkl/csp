#include<stdio.h>

int main(){
    int n, N;
    int a[200 + 10];
    scanf("%d%d",&n, &N);
    a[0] = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    a[n + 1] = N;
    int sum = 0;
    for(int i = 0; i <= n; i++){
        sum += i * (a[i + 1] - a[i]);
    }
    printf("%d", sum);
}