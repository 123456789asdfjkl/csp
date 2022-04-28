#include "cstdio"

int main(){
    int n;
    scanf("%d", &n);
    int a[100000 + 10];
    int flag = 0;
    scanf("%d", &a[0]);
    for (int i = 1; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] > a[i - 1]){
            if (flag == 0) {
                flag = 1;
            }
        }
    }
    int min, max;
    // flag为1时为升序，0为降序
    if (flag){
        max = a[n - 1];
        min = a[0];
        if (n % 2 == 0){
            if (a[n / 2] % 2 == a[n / 2 - 1] % 2){
                printf("%d %d %d",max, (a[n / 2]+a[n / 2 - 1]) / 2, min);
            }else{
                printf("%d %.1f %d", max, (a[n / 2]+a[n / 2 - 1]) / 2.0, min);
            }
        } else{
            printf("%d %d %d", max, a[n/2], min);
        }
    }else{
        max = a[0];
        min = a[n - 1];
        if (n % 2 == 0){
            if (a[n / 2] % 2 == a[n / 2 - 1] % 2){
                printf("%d %d %d",max, (a[n / 2]+a[n / 2 - 1]) / 2, min);
            }else{
                printf("%d %.1f %d", max, (a[n / 2]+a[n / 2 - 1]) / 2.0, min);
            }
        } else{
            printf("%d %d %d", max, a[n/2], min);
        }
    }
    return 0;
}
/*
3
-1 2 4
4
-2 -1 3 4
 */
