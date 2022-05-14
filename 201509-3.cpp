#include<iostream>
#include "map"
#include "string"
using namespace std;
const int MAXN = 100 + 10;

int main() {
    int m, n;
    map<string, string> mp;
    string C[MAXN];
    cin >> m >> n;
    getchar();
    for (int i = 1; i <= m; i++) {
        getline(cin, C[i]);
    }
    for (int i = 1; i <= n; i++) {
        string kk, a, b;
        getline(cin, kk);
        int len = kk.size();
        int idx = kk.find(" ");
        a = kk.substr(0, idx);
        b = kk.substr(idx + 2, len - idx - 3);
        mp[a] = b;
    }
    for (int i = 1; i <= m; i++) {
        int now_idx = 0;
        while (1) {
            int p1 = C[i].find("{{", now_idx);
            int p2 = C[i].find("}}", now_idx);
            if (p1 == -1 || p2 == -1)break;
            string tmp = C[i].substr(p1 + 3, p2 - p1 - 4);
            C[i].replace(p1, p2 - p1 + 2, mp.count(tmp) ? mp[tmp] : "");
            now_idx = p1 + mp[tmp].size();
        }
        cout << C[i] << endl;
    }
}