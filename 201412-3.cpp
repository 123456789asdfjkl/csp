#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>

using namespace std;
struct Node {
    bool isSell;//是否为卖方
    double price;//价格
    int number;//股数
} node[5010];
long long int buy[5010] = {0}, sell[5010] = {0};

bool cmp(Node a, Node b) {
    if (a.price == b.price) return a.isSell > b.isSell;
    return a.price < b.price;
}

int main() {
    int count = 1, num;
    string str;
    //输入数据
    while (cin >> str) {
        double price, number;
        if (str == "buy") {
            cin >> node[count].price >> node[count].number;
            node[count].isSell = false;
        } else if (str == "sell") {
            cin >> node[count].price >> node[count].number;
            node[count].isSell = true;
        } else {
            cin >> num;
            node[num].price = node[num].number = 0;
        }
        count++;
    }
    //按价格从小到大排序，卖方放左边
    sort(node, node + count, cmp);
    int left = 1, high = count - 1;
    long long int ans = 0, bestans = 0, cum = 0;
    double p = 0;
    while (node[left].price == 0) left++;
    //从两个方向累计买家和卖家
    for (int i = high; i >= left; i--) {
        if (node[i].isSell == false)cum += node[i].number;
        buy[i] = cum;
    }
    cum = 0;
    for (int i = left; i <= high; i++) {
        if (node[i].isSell == true)cum += node[i].number;
        sell[i] = cum;
    }
    for (int i = left; i <= high; i++) {
        ans = min(sell[i], buy[i]);
        if (ans >= bestans) {
            bestans = ans;
            p = node[i].price;
        }
    }
    printf("%.2lf %lld", p, bestans);
    return 0;
}
