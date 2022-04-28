#include "cstdio"

int main(){
    int N, M;
    scanf("%d%d",&N,&M);
    int a;
    int T = 0;
    int k = 1;
    int P = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a);
        T += a;
        int sum = 0;
        for (int j = 1; j <= M; ++j) {
            scanf("%d", &a);
            T += a;
            sum -= a;
            if(sum>P){
                P = sum;
                k = i + 1;
            }
        }
    }
    printf("%d %d %d", T, k, P);
    return 0;
}
/*
3 3
73 -8 -6 -4
76 -5 -10 -8
80 -6 -15 0
2 2
10 -3 -1
15 -4 0
*/