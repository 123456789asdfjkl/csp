#include "stdio.h"
#include "vector"

struct row {
    int num[5] = {0};
};

int main() {
    int n;
    std::vector<row> vi[20];
    int row_num[20] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
    int ticket_nums[100 + 10];
    int flag = 1;
    int break_flag = 0;
    for (int i = 0; i < 20; ++i) {
        row temp;
        vi[i].push_back(temp);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &ticket_nums[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (row_num[j] >= ticket_nums[i]) {
                int k;
                for (k = 0; k < 5; ++k) {
                    if (vi[j][0].num[k] == 0) {
                        break;
                    }
                }
                for (int l = k; l < k + ticket_nums[i]; ++l) {
                    vi[j][0].num[l] = 1;
                    printf("%d", j * 5 + l + 1);
                    if (l < k + ticket_nums[i]) {
                        printf(" ");
                    }
                }
                row_num[j] -= ticket_nums[i];
                flag = 0;
                break;
            }
        }
        if (flag) {
            int temp_ticket_nums = ticket_nums[i];
            for (int j = 0; j < 20; ++j) {
                if (row_num[j] != 0) {
                    for (int k = 0; k < 5; ++k) {
                        if (vi[j][0].num[k] == 0) {
                            vi[j][0].num[k] = 1;
                            printf("%d", j * 5 + k + 1);
                            row_num[j]--;
                            temp_ticket_nums--;
                            if (temp_ticket_nums > 0) {
                                printf(" ");
                            } else {
                                break_flag = 1;
                                break;
                            }
                        }
                    }
                }
                if (break_flag) {
                    break;
                }
            }
        }
        flag = 1;
        break_flag = 0;
        if (i < n - 1) {
            printf("\n");
        }
    }
};

/*
22
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3
 */