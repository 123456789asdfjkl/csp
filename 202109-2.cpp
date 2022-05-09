#include "stdio.h"
#include "algorithm"
#include "vector"

int main() {
    int n;
    int a[500000 + 10] = {0};
    int sum = 0;
    std::vector<int> candinate;
    int flag[10000 + 10] = {0};
    flag[0] = 1;
    std::vector<int> vi[10000 + 10];
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] != 0 && a[i - 1] == 0) {
            sum++;
        }
        if (flag[a[i]] == 0) {
            candinate.push_back(a[i]);
            flag[a[i]] = 1;
        }
        vi[a[i]].push_back(i);
    }
    if ((n % 2 == 0 && (n - 2) / 2 + 1 == sum) || (n % 2 == 1 && n / 2 + 1 == sum) || (sum == 0)) {
        printf("%d", sum);
        return 0;
    }
    int max_sum = sum;
    std::sort(candinate.begin(), candinate.end());
    for (int i = 1; i < candinate.size() + 1; ++i) {
        int temp = candinate[i - 1];
        for (int j = 0; j < vi[temp].size(); ++j) {
            int pos = vi[temp][j];
            if (a[pos - 1] == 0 && a[pos + 1] == 0) {
                sum--;
            } else if (a[pos - 1] > 0 && a[pos + 1] > 0) {
                sum++;
            }
            a[pos] = 0;
        }
        if (max_sum < sum) {
            max_sum = sum;
        }
    }
    printf("%d", max_sum);
    return 0;
}