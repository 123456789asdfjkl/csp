#include "stdio.h"

int game_over(int a, int k) {
    if (a % k == 0 || a % 10 == k) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n, k;
    int flag[1000 + 10] = {0};
    scanf("%d%d", &n, &k);
    int count = n;
    int winner;
    int num = 1;
    int pos = 1;
    while (count > 1 && n > 1) {
        if (game_over(num, k)) {
            flag[pos] = 1;
            count--;
        }
        num++;
        for (int i = pos + 1; i < n + pos; ++i) {
            if (flag[(i - 1) % n + 1] == 0) {
                pos = (i - 1) % n + 1;
                break;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (flag[i] == 0) {
            winner = i;
            break;
        }
    }
    printf("%d", winner);
    return 0;
}