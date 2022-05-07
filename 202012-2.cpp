#include "stdio.h"
#include "vector"
#include "algorithm"
#include "map"

int main() {
    int m;
    std::map<int, int> mp0; // 存储0类的值和个数
    std::map<int, int> mp1; // 存储1类的值和个数
    std::vector<int> ans;   // 记录答案阈值
    int max_num = 0;    // 记录预测正确的最大值
    std::vector<int> candidate; // 保存所有候选答案
    std::vector<int> vi1;   // 记录第i个候选值对1类的得分
    std::vector<int> vi0;   // 记录第i个候选值对2类的得分
    int y;
    int result;
    int theta;
    int sum = 0;    // 记录1类样本的总个数
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%", &y, &result);
        if (result == 0) {
            if (mp0.find(y) != mp0.end()) {
                mp0[y]++;
            } else {
                mp0[y] = 1;
            }
        } else {
            if (mp1.find(y) != mp1.end()) {
                mp1[y]++;
            } else {
                mp1[y] = 1;
            }
            sum++;
        }
        if (std::find(candidate.begin(), candidate.end(), y) == candidate.end()) {
            candidate.push_back(y);
        }
    }
    std::sort(candidate.begin(), candidate.end());
    vi1.push_back(sum);
    vi0.push_back(0);
    max_num = sum;
    ans.push_back(candidate[0]);
    for (int i = 1; i < candidate.size(); ++i) {
        theta = candidate[i];
        int count0;
        int count1;
        if (mp0.find(candidate[i - 1]) != mp0.end()) {
            count0 = vi0[i - 1] + mp0[candidate[i - 1]];
        } else {
            count0 = vi0[i - 1];
        }
        if (mp1.find(candidate[i - 1]) != mp1.end()) {
            count1 = vi1[i - 1] - mp1[candidate[i - 1]];
        } else {
            count1 = vi1[i - 1];
        }
        int count = count0 + count1;
        vi0.push_back(count0);
        vi1.push_back(count1);
        if (count > max_num) {
            max_num = count;
            ans.clear();
            ans.push_back(theta);
        } else if (count == max_num) {
            ans.push_back(theta);
        }
    }
    printf("%d", ans[ans.size() - 1]);
    return 0;
}