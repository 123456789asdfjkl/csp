#include "stdio.h"
#include "algorithm"

int main(){
    int n;
    int count[1000 + 10] = {0};
    int a[1000 + 10];
    int sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
        count[a[i]]++;
        sum++;
    }
    std::sort(a, a + n);
    int left = 0, right = 0;
    for (int i = 0; i < a[n / 2]; ++i) {
        left += count[i];
    }
    for (int i = a[n / 2] + 1; i <= a[n - 1]; ++i) {
        right += count[i];
    }
    if (right == left){
        printf("%d", a[n/2]);
    } else{
        printf("-1");
    }
    return 0;
}
