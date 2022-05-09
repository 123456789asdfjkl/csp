#include <algorithm>
#include "stdio.h"

using namespace std;

int main() {
    int n;
    int s[100000 + 10];
    pair<int, int> w[100000 + 10];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &w[i].first, &w[i].second);
    }

    sort(w + 1, w + 1 + n);


    s[n + 1] = 0;
    for (int i = n; i > 0; i--) {
        s[i] = s[i + 1] + w[i].second;
    }
    /*
        s[i]: y >= yi时，成绩是1的数量(后缀和)
    */

    int ans = 0;
    int num = 0;
    for (int i = n; i > 0; i--) {
        if (w[i].first == w[i - 1].first) continue;
        if (s[i] + i - (s[1] - s[i]) > num)
        {
            num = s[i] + i - (s[1] - s[i]);
            ans = w[i].first;
        }
    }
    printf("%d", ans);
}
