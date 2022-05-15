#include "iostream"
#include "stack"

std::stack<std::pair<int, int>> s;

void padding(int x, int y, int c, int n, int m, char ans[100 + 10][100 + 10]) {
    for (int j = x + 1; j < n; ++j) {
        if (ans[j][y] == '|' || ans[j][y] == '-' || ans[j][y] == '+') {
            break;
        } else if (ans[j][y] != c) {
            ans[j][y] = c;
            s.push(std::make_pair(j, y));
        }
    }
    for (int j = x - 1; j >= 0; --j) {
        if (ans[j][y] == '|' || ans[j][y] == '-' || ans[j][y] == '+') {
            break;
        } else if (ans[j][y] != c) {
            ans[j][y] = c;
            s.push(std::make_pair(j, y));
        }
    }
    for (int j = y + 1; j < m; ++j) {
        if (ans[x][j] == '|' || ans[x][j] == '-' || ans[x][j] == '+') {
            break;
        } else if (ans[x][j] != c) {
            ans[x][j] = c;
            s.push(std::make_pair(x, j));
        }
    }
    for (int j = y - 1; j >= 0; --j) {
        if (ans[x][j] == '|' || ans[x][j] == '-' || ans[x][j] == '+') {
            break;
        } else if (ans[x][j] != c) {
            ans[x][j] = c;
            s.push(std::make_pair(x, j));
        }
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
            s.push(std::make_pair(y, x));
            while (!s.empty()) {
                auto temp1 = s.top();
                s.pop();
                ans[temp1.first][temp1.second] = c;
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