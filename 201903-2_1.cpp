#include "stdio.h"
#include "string"
#include "iostream"
#include "queue"

int main() {
    int n;
    std::string str;
    std::queue<int> number;
    std::queue<char> op;
    char op_temp;
    int a, b;
    int c;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        std::cin >> str;
        int sum = 0;
        for (int j = 0; j < str.size(); ++j) {
            if (str[j] > '0' && str[j] <= '9') {
                number.push(str[j] - '0');
            } else if (str[j] == 'x') {
                number.back() *= (str[++j] - '0');
            } else if (str[j] == '/') {
                number.back() /= (str[++j] - '0');
            } else if (str[j] == '+' || str[j] == '-') {
                op.push(str[j]);
            }
        }
        while (!op.empty()) {
            a = number.front();
            number.pop();
            op_temp = op.front();
            op.pop();
            if (op_temp == '+') {
                number.front() = a + number.front();
            } else if (op_temp == '-') {
                number.front() = a - number.front();
            }
        }
        sum = number.front();
        number.pop();
        if (sum == 24) {
            printf("Yes");
        } else {
            printf("No");
        }
        if (i < n - 1) {
            printf("\n");
        }
    }

    return 0;
}

/*
10
9+3+4x3
5+4x5x5
7-9-9+8
5x6/5x4
3+5+7+9
1x1+9-9
1x9-5/9
8/5+6x9
6x7-3x6
6x4+4/5

 */