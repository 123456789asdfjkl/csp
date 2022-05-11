#include "stdio.h"
#include "stack"
#include "algorithm"

// 栈存储的是当前元素的左边界，从左至右寻找的是栈顶元素的右边界

int main() {
    int n;
    std::stack<int> s;
    int a[1000 + 10];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    a[n] = 0;
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (s.empty() || a[i] > a[s.top()]) {
            s.push(i);
        } else {
            int temp;
            while (!s.empty() && a[i] < a[s.top()]) {
                temp = s.top();
                s.pop();
                ans = std::max(ans, (i - temp) * a[temp]);
            }
            s.push(temp);
            a[temp] = a[i];
        }
    }
    printf("%d", ans);
    return 0;
}