#include "stdio.h"
#include "vector"

int main() {
    int n, m;
    std::vector<int> vi;
    int query, dis;
    int pos;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        vi.push_back(i + 1);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &query, &dis);
        int j;
        for (j = 0; j < vi.size(); ++j) {
            if (vi[j] == query) {
                break;
            }
        }
        vi.erase(vi.begin() + j);
        if (dis > 0) {
            vi.insert(vi.begin() + j + dis, query);
        } else {
            vi.insert(vi.begin() + j + dis , query);
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d", vi[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    return 0;
}