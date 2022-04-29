#include "stdio.h"
#include "string"
#include "iostream"

using namespace std;

int main() {
    std::string str;
    std::cin >> str;
    int result = 0;
    for (int i = 0; i < str.length(); ++i) {
        result += str[i] - '0';
    }
    printf("%d", result);
    return 0;
}