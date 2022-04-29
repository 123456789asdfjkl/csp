#include "stdio.h"

int main() {
    int n;
    int s;
    int count[10000 + 10] = {0};
    int max_number;
    int max_count = 1;
    scanf("%d", &n);
    scanf("%d", &max_number);
    count[max_number]++;
    for (int i = 1; i < n; ++i) {
        scanf("%d", &s);
        count[s]++;
        if (count[s] > max_count) {
            max_number = s;
            max_count = count[s];
        } else if (count[s] == max_count) {
            if (s < max_number) {
                max_number = s;
            }
        }
    }
    printf("%d", max_number);
    return 0;
}