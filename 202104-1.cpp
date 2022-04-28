#include "stdio.h"

int main(){
    int n, m, L;
    int a;
    scanf("%d%d%d",&n,&m,&L);
    int b[256 + 10]={0};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a);
            b[a]++;
        }
    }
    for (int i = 0; i < L; ++i) {
        printf("%d ",b[i]);
    }
    return 0;
}
