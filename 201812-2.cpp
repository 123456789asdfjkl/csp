#include "stdio.h"

int main() {
    int r, y, g;
    scanf("%d%d%d", &r, &y, &g);
    int n;
    scanf("%d", &n);
    long long int sum = 0;//可能会超界
    int k, t;
    while (n--) {
        scanf("%d%d", &k, &t);
        /*可能到达红绿灯时已经过多轮循环，不需要计算循环时间 */
        int temp = sum % (r + y + g);
        /*以下分支相同处理，分别将其处于每个时间段情况列出即可 */
        switch (k) {
            case 0://直接通过
                sum += t;
                break;
            case 1://出发时为红灯
                if (temp < t)//到达仍为红灯
                    sum += t - temp;
                else if (temp >= t && temp < t + g);//到达时已经变为绿灯
                else if (temp >= t + g && temp < t + g + y)//到达时已经变为黄灯
                    sum += t + g + y - temp + r;
                else if (temp >= t + g + y)//到达时可能又变为红灯
                    sum += t + g + y + r - temp;
                break;
            case 2://出发时为黄灯
                if (temp < t)//到达仍为黄灯
                    sum += t - temp + r;
                else if (temp >= t && temp < t + r)//到达时已经变为红灯
                    sum += t + r - temp;
                else if (temp >= t + r && temp < t + r + g);//到达时已经变为绿灯
                else if (temp >= t + r + g)//到达时可能又变为黄灯
                    sum += t + r + g + y - temp + r;
                break;
            case 3://出发时为绿灯
                if (temp < t);//到达时已经变为绿灯
                else if (temp >= t && temp < t + y)//到达时已经变为黄灯
                    sum += t + y - temp + r;
                else if (temp >= t + y && temp < t + y + r)//到达时已经变为红灯
                    sum += t + y + r - temp;
                else if (temp >= t + y + r);//到达时可能又变为绿灯
                break;
        }
    }
    printf("%lld",sum);
    return 0;
}
