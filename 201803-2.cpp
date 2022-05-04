#include "stdio.h"
#include "vector"

int main() {
    int n, L, t;
    int state[100 + 10] = {0};
    int a[100 + 10];
    scanf("%d%d%d", &n, &L, &t);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < t; ++i) {
        int length_count[1000 + 10] = {0};
        std::vector<int> vi[1000 + 10];
        int flag[100 + 10] = {0};
        for (int j = 0; j < n; ++j) {
            if (state[j] == 0) {
                a[j]++;
            } else {
                a[j]--;
            }
            length_count[a[j]]++;
            vi[a[j]].push_back(j);
        }
        for (int j = 0; j < L; ++j) {
            if (length_count[j] > 1) {
                for (int k = 0; k < vi[j].size(); ++k) {
                    state[vi[j][k]] = 1 - state[vi[j][k]];
                    flag[vi[j][k]] = 1;
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            if (flag[j] == 0) {
                if (a[j] == L) {
                    state[j] = 1;
                }
                if (a[j] == 0) {
                    state[j] = 0;
                }

            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d", a[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    return 0;
}