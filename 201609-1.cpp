#include "stdio.h"
#include "algorithm"
#include "math.h"

int main(){
    int n;
    int a[1000 + 10];
    int difference[1000 + 10];
    scanf("%d", &n);
    scanf("%d",&a[0]);
    for (int i = 1; i < n; ++i) {
        scanf("%d",&a[i]);
        difference[i-1] = abs(a[i] - a[i - 1]);
    }
    std::sort(difference, difference + n -1);
    printf("%d", difference[n-2]);
    return 0;
}
