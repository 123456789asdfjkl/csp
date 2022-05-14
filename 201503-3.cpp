#include "stdio.h"
#include "algorithm"

int isyear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int a, b, c, y1, y2;
    int year[2] = {365, 366};
    int month[2][13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
                        0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d%d%d%d%d", &a, &b, &c, &y1, &y2);
    if (y1 > y2) {
        std::swap(y1, y2);
    }
    int week_temp = 2;
    for (int i = 1850; i < y1; ++i) {
        week_temp = (week_temp + year[isyear(i)] % 7 - 1) % 7 + 1;
    }
    for (int k = y1; k <= y2; ++k) {
        int week_temp1 = week_temp;
        int year_flag = isyear(k);
        for (int i = 1; i < a; ++i) {
            week_temp1 = (week_temp1 + month[year_flag][i] % 7 - 1) % 7 + 1;
        }
        int count = 0;
        int i;
        int flag = 0;
        for (i = 1; i <= month[year_flag][a]; ++i) {
            if (week_temp1 == c) {
                count++;
            }
            if (count == b) {
                flag = 1;
                break;
            }
            week_temp1 = week_temp1 % 7 + 1;
        }
        if (flag) {
            printf("%4d/%02d/%02d\n", k, a, i);
        } else {
            printf("none\n");
        }
        week_temp = (week_temp + year[isyear(k)] % 7 - 1) % 7 + 1;
    }
    return 0;
}