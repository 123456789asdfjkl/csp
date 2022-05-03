#include "stdio.h"
#include "vector"

struct coordinate {
    int x1;
    int y1;
    int x2;
    int y2;
    int number;
};

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    std::vector<coordinate> windows;
    coordinate co;
    int x, y;
    for (int i = 0; i < N; ++i) {
        scanf("%d%d%d%d", &co.x1, &co.y1, &co.x2, &co.y2);
        co.number = i + 1;
        windows.insert(windows.begin(), co);
    }
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &x, &y);
        int j;
        for (j = 0; j < windows.size(); ++j) {
            if (x >= windows[j].x1 && y >= windows[j].y1 && x <= windows[j].x2 && y <= windows[j].y2) {
                printf("%d\n", windows[j].number);
                co = windows[j];
                windows.erase(windows.begin() + j);
                windows.insert(windows.begin(), co);
                break;
            }
        }
        if (j == windows.size()) {
            printf("IGNORED\n");
        }
    }
    return 0;
}