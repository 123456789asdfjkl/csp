#include "stdio.h"
#include "vector"

struct coordinate {
    int i;
    int j;
};

int main() {
    int a[15 + 1][10 + 1];
    int b[4 + 1][4 + 1];
    int pos;
    int flag = 0;
    std::vector<coordinate> vi;
    for (int i = 1; i <= 15; ++i) {
        for (int j = 1; j <= 10; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            scanf("%d", &b[i][j]);
            if (b[i][j] == 1) {
                coordinate co;
                co.i = i;
                co.j = j;
                vi.push_back(co);
            }
        }
    }
    scanf("%d", &pos);
    int i;
    for (i = 1; i <= 15; ++i) {
        for (int j = 0; j < vi.size(); ++j) {
            int x, y;
            x = vi[j].i;
            y = vi[j].j;
            if (a[x + i][y + pos - 1] == 1) {
                flag = 1;
                break;
            } else if (x + i - 1 == 15) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            break;
        }
    }
    for (int j = 0; j < vi.size(); ++j) {
        int x, y;
        x = vi[j].i;
        y = vi[j].j;
        a[x + i - 1][y + pos - 1] = 1;
    }


    for (int i = 1; i <= 15; ++i) {
        for (int j = 1; j <= 10; ++j) {
            printf("%d", a[i][j]);
            if (j < 10) {
                printf(" ");
            }
        }
        if (i < 15) {
            printf("\n");
        }
    }
    return 0;
}
/*
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0
0 1 1 1
0 0 0 1
0 0 0 0
3
 */