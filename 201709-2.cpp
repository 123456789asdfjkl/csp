#include "stdio.h"
#include "vector"
#include "algorithm"

struct thing {
    int w;
    int t;
    int borrow_flag;
};

int cmp(thing a, thing b) {
    if (a.t > b.t) {
        return 0;
    }
    if (a.t == b.t) {
        if (a.borrow_flag == 1 && b.borrow_flag == 0) {
            return 0;
        }
        if (a.borrow_flag == 0 && b.borrow_flag == 1) {
            return 1;
        }
        if (a.w > b.w) {
            return 0;
        } else {
            return 1;
        }
    }
    return 1;
};

int main() {
    int N, K;
    std::vector<thing> things;
    int flag[1000 + 10] = {0};
    int pos[1000 + 10];
    int w, s, c;
    thing th;
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; ++i) {
        pos[i] = i;
    }
    for (int i = 0; i < K; ++i) {
        scanf("%d%d%d", &w, &s, &c);
        th.w = w;
        th.t = s;
        th.borrow_flag = 1;
        things.push_back(th);
        th.w = w;
        th.t = s + c;
        th.borrow_flag = 0;
        things.push_back(th);
    }
    std::sort(things.begin(), things.end(), cmp);
    for (int i = 0; i < things.size(); ++i) {
        if (things[i].borrow_flag == 1) {
            int j;
            for (j = 1; j <= N; ++j) {
                if (things[i].w == pos[j]) {
                    break;
                }
            }
            pos[j] = -1;
            flag[j] = 1;
        } else {
            int j;
            for (j = 1; j <= N; ++j) {
                if (flag[j] == 1) {
                    break;
                }
            }
            pos[j] = things[i].w;
            flag[j] = 0;
        }
    }
    for (int i = 1; i <= N; ++i) {
        printf("%d", pos[i]);
        if (i < N) {
            printf(" ");
        }
    }
    return 0;
}