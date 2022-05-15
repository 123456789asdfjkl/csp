/*
 * 广度优先搜索
 */

#include "iostream"
#include "stack"

std::stack<std::pair<int, int>> s;

void padding(int x, int y, int c, int n, int m, char ans[100 + 10][100 + 10]) {
    if (ans[x + 1][y] == '|' || ans[x + 1][y] == '-' || ans[x + 1][y] == '+' || (x + 1 >= n)) {

    } else if (ans[x + 1][y] != c) {
        ans[x + 1][y] = c;
        s.push(std::make_pair(x + 1, y));
    }
    if (ans[x - 1][y] == '|' || ans[x - 1][y] == '-' || ans[x - 1][y] == '+' || (x - 1 < 0)) {

    } else if (ans[x - 1][y] != c) {
        ans[x - 1][y] = c;
        s.push(std::make_pair(x - 1, y));
    }
    if (ans[x][y + 1] == '|' || ans[x][y + 1] == '-' || ans[x][y + 1] == '+' || (y + 1 >= m)) {

    } else if (ans[x][y + 1] != c) {
        ans[x][y + 1] = c;
        s.push(std::make_pair(x, y + 1));
    }
    if (ans[x][y - 1] == '|' || ans[x][y - 1] == '-' || ans[x][y - 1] == '+' || (y - 1 < 0)) {

    } else if (ans[x][y - 1] != c) {
        ans[x][y - 1] = c;
        s.push(std::make_pair(x, y - 1));
    }
}

int main() {
    int m, n, q;
    int x1, y1, x2, y2;
    int x, y;
    char c;
    int temp;
    std::cin >> m >> n >> q;
    char ans[100 + 10][100 + 10];
    for (int i = 0; i < 100 + 10; ++i) {
        for (int j = 0; j < 100 + 10; ++j) {
            ans[i][j] = '.';
        }
    }
    for (int i = 0; i < q; ++i) {
        std::cin >> temp;
        if (temp == 0) {
            std::cin >> x1 >> y1 >> x2 >> y2;
            if (x1 == x2) {
                if (y1 > y2) {
                    std::swap(y1, y2);
                }
                for (int j = y1; j <= y2; ++j) {
                    if (ans[j][x1] == '-') {
                        ans[j][x1] = '+';
                    } else if (ans[j][x1] != '+') {
                        ans[j][x1] = '|';
                    }
                }
            } else {
                if (x1 > x2) {
                    std::swap(x1, x2);
                }
                for (int j = x1; j <= x2; ++j) {
                    if (ans[y1][j] == '|') {
                        ans[y1][j] = '+';
                    } else if (ans[y1][j] != '+') {
                        ans[y1][j] = '-';
                    }
                }
            }
        } else {
            std::cin >> x >> y >> c;
            ans[y][x] = c;
            s.push(std::make_pair(y, x));
            while (!s.empty()) {
                auto temp1 = s.top();
                s.pop();
                padding(temp1.first, temp1.second, c, n, m, ans);
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            std::cout << ans[i][j];
        }
        if (i > 0) {
            std::cout << std::endl;
        }
    }
    return 0;
}