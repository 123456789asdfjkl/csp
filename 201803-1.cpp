#include "stdio.h"

int main(){
    int a[30 + 1];
    int sum = 0;
    for (int i = 0; i < 30; ++i) {
        scanf("%d",&a[i]);
        if(a[i] == 1){
            sum +=1;
        } else if (a[i] == 2){
            for (int j = i; j >= 0 && a[j] == 2; --j) {
                sum += 2;
            }
        } else if (a[i] == 0){
            break;
        }
    }
    printf("%d",sum);
    return 0;
}