#include <cstdio>

int ans(int num){
    if (num % 7 == 0){
        return 1;
    }
    while (num!=0){
        if (num % 10 == 7){
            return 1;
        }
        num /= 10;
    }
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    int a[4] = {0};
    int i = 1, j = 0;
    while(i <= n){
        if (ans(j + 1)){
            a[j % 4]++;
        }else{
            i++;
        }
        j++;
    }
    for (int i = 0; i < 4; ++i) {
        printf("%d\n",a[i]);
    }
    return 0;
}