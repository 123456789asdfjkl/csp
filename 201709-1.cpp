#include "stdio.h"

int main(){
    int n;
    scanf("%d", &n);
    int a = 0;
    a = n / 50 * 7 + (n - n / 50 * 50) / 30 * 4 + ((n - n / 50 * 50) - (n - n / 50 * 50) / 30 * 30) / 10;
    printf("%d", a);
    return 0;
}