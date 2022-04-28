#include <bits/stdc++.h>
using namespace std;

/*
 * g(i)的前k（这里k从0开始）项，是由r个首项为0、项数为(k + 1) / r、公差为1的等差数列，以及(k + 1) % r个k / r构成的
 */

long long h(long long i, long long r) { //求g(i)的前缀和h(i)
    if (i < 0) return 0;
    else return r * ((i + 1) / r - 1) * ((i + 1) / r) / 2 + (i + 1) % r * (i / r);
}

long long cal(long long fi, long long lft, long long rgt, long long r) { //给定一个f(i),计算区间里的|g(i)-f(i)|之和,前提是g(i)全部小于等于或者全部大于等于f(i)
    return abs(h(rgt, r) - h(lft - 1, r) - fi * (rgt - lft + 1));
}

int main()
{
    int n, N;
    long long int a[100000 + 10];
    scanf("%d%d", &n, &N);
    a[0] = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    a[n + 1] = N;
    long long r = N / (n + 1), ans = 0;
    for (long long fi = 0; fi <= n; ++fi) { //遍历每个f(i)
        long long lft = a[fi], rgt = a[fi + 1] - 1;
        if (lft / r >= fi || rgt / r <= fi){ //如果区间内g(i)全部小于等于或者全部大于等于f(i),直接使用cal函数
            ans += cal(fi, lft, rgt, r);
        }else{ //否则将区间分成两半，分别使用cal函数
            ans += cal(fi, lft, r * fi, r) + cal(fi, r * fi + 1, rgt, r);
        }
    }
    printf("%d", ans);
    return 0;
}
