#include "stdio.h"

int main() {
    int N;
    int apple_nums[1000 + 10];
    int drop_flag[1000 + 10] = {0};
    int T = 0;
    int D = 0;
    int E = 0;
    int m, a;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &m);
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a);
            if (j == 0) {
                apple_nums[i] = a;
                continue;
            }
            if (a > 0) {
                if (a < apple_nums[i]) {
                    drop_flag[i] = 1;
                    apple_nums[i] = a;
                }
            } else if (a < 0) {
                apple_nums[i] += a;
            }
        }
        T += apple_nums[i];
        if (drop_flag[i] == 1) {
            D++;
        }
    }
    for (int i = 0; i < N; ++i) {
        if (drop_flag[i] == 1 && drop_flag[(i + 1 + N) % N] == 1 && drop_flag[(i - 1 + N) % N] == 1) {
            E++;
        }
    }
    printf("%d %d %d", T, D, E);
    return 0;
}

/*
4
4 74 -7 -12 -5
5 73 -8 -6 59 -4
5 76 -5 -10 60-2
5 80 -6 -15 59 0
5
4 10 0 9 0
4 10 -2 7 0
2 10 0
4 10 -3 5 0
4 10 -1 8 0
 */