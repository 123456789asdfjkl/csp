#include "iostream"
#include "stdio.h"
#include "string"

using namespace std;

int main() {
    string s;
    cin >> s;
    int char_count = 0;
    int sum = 0;
    int number_count = 1;
    string temp_s;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != '-') {
            if (char_count == 3) {
                if ((sum % 11 == (s[i] - '0')) || (sum % 11 == 10 && s[i] == 'X')) {
                    printf("Right");
                } else {
                    if (sum % 11 == 10) {
                        temp_s += 'X';
                    } else {
                        temp_s += ('0' + sum % 11);
                    }
                    cout << temp_s;
                }
                break;
            } else {
                sum += (s[i] - '0') * number_count;
                number_count++;
            }
        } else {
            char_count++;
        }
        temp_s += s[i];
    }
    return 0;
}