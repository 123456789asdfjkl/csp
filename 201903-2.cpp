#include "stdio.h"
#include "string"
#include "iostream"
#include "stack"

// 需要考虑减法操作，如果使用栈的话最好将减法转为加法，此题也可以考虑队列来做

int main() {
    int n;
    std::string str;
    std::stack<int> number;
    std::stack<char> op;
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
            }
            if (str[j] == 'x') {
                j++;
                a = str[j] - '0';
                b = number.top();
                number.pop();
                c = b * a;
                number.push(c);
            }
            if (str[j] == '/') {
                j++;
                a = str[j] - '0';
                b = number.top();
                number.pop();
                c = b / a;
                number.push(c);
            }
            if (str[j] == '+') {
                op.push(str[j]);
            }
            if (str[j] == '-'){
                j++;
                number.push('0'-str[j]);
                op.push('+');
            }
        }
        while (!op.empty()) {
            a = number.top();
            number.pop();
            b = number.top();
            number.pop();
            op.pop();
            c = b + a;
            number.push(c);
        }
        sum = number.top();
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