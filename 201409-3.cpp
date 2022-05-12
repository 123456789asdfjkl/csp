#include "iostream"
#include "string"
#include "algorithm"

int main() {
    int type, n;
    std::string pattern;
    std::string s;
    std::cin >> pattern;
    std::cin >> type;
    std::cin >> n;
    std::cin.ignore();

    if (type == 0) {
        std::transform(pattern.begin(), pattern.end(), pattern.begin(), ::tolower);
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> s;
        std::string temp = s;
        if (type == 0) {
            std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        }
        if (temp.find(pattern) < temp.size()) {
            std::cout << s << std::endl;
        }
    }
    return 0;
}