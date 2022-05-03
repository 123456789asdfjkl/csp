#include "stdio.h"

const int a[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                      {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int isyear(int year) {
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int y, d;
    scanf("%d%d", &y, &d);
    int month;
    int flag = isyear(y);
    int i = 0;
    for (month = 1; month <= 13; ++month) {
        if (a[flag][month] + i >= d) {
            break;
        } else {
            i += a[flag][month];
        }
    }
    printf("%d\n%d", month, d - i);
    return 0;
}