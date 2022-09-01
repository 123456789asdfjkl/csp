#include "stdio.h"
#include "math.h"

int main(){
    int n;
    int a[1000 + 10];
    double ans[1000 + 10];
    scanf("%d",&n);
    double temp1=0, temp2=0;   //temp1存储ai的和，temp2存储ai的平方和
    double mean, var;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
        temp1 += a[i];
        temp2 += a[i] * a[i];
    }
    mean = temp1 / n;
    var = temp2 / n - mean * mean;
    for (int i = 0; i < n; ++i) {
        printf("%f\n", (a[i] - mean) / sqrt(var));
    }
    return 0;
}