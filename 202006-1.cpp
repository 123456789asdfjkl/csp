#include "stdio.h"
#include "vector"
#include "algorithm"
using namespace std;

int main(){
    int n,m;
    int theta0,theta1,theta2;
    int a,b;
    vector<pair<int,int>> xyA;
    vector<pair<int,int>> xyB;
    char c;
    scanf("%d%d", &n,&m);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %c",&a,&b,&c);
//        scanf("%c",&c);
        if (c == 'A'){
            xyA.push_back(make_pair(a,b));
        }else{
            xyB.push_back(make_pair(a,b));
        }
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &theta0,&theta1,&theta2);
        int flag = true;
        int xyA_flag, xyB_flag,xy_flag;
        if (theta0 + theta1 * xyA[0].first + theta2 * xyA[0].second > 0){
            xyA_flag = 1;
            xyB_flag = 0;
        } else{
            xyA_flag = 0;
            xyB_flag = 1;
        }
        for (int j = 1; j < xyA.size(); ++j) {
            if (theta0 + theta1 * xyA[j].first + theta2 * xyA[j].second > 0){
                xy_flag = 1;
            } else{
                xy_flag = 0;
            }
            if (xy_flag != xyA_flag){
                printf("No\n");
                flag = false;
                break;
            }
        }
        if (flag) {
            for (int j = 0; j < xyB.size(); ++j) {
                if (theta0 + theta1 * xyB[j].first + theta2 * xyB[j].second > 0){
                    xy_flag = 1;
                } else{
                    xy_flag = 0;
                }
                if (xy_flag != xyB_flag){
                    printf("No\n");
                    flag = false;
                    break;
                }
            }
        }

        if (flag){
            printf("Yes\n");
        }
        flag = true;
    }
    return 0;
}
/*
9 3
1 1 A
1 0 A
1 -1 A
2 2 B
2 3 B
0 1 A
3 1 B
1 3 B
2 0 A
-3 1 1
0 2 -3
-3 0 2
*/