#include "stdio.h"
#include "algorithm"

int main(){
    int n;
    int a[1000+10];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    std::sort(a,a+n);
    int min = a[1]-a[0];
    for (int i = 2; i < n; ++i) {
        min = std::min(min, a[i]-a[i-1]);
    }
    printf("%d", min);
    return 0;
}