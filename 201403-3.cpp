#include <sstream>
#include "string"
#include "iostream"

int main() {
    int n;
    std::string pattern, s;
    int type[30] = {0};
    std::cin >> pattern;

    for (int i = 0; i < pattern.size(); ++i) {
        if (pattern[i] == ':') {
            type[pattern[i - 1] - 'a'] = 2;
        } else {
            type[pattern[i] - 'a'] = 1;
        }
    }

    std::cin >> n;
    std::cin.ignore();
    for (int i = 1; i <= n; ++i) {
        getline(std::cin, s);
        std::stringstream ss(s);
        std::string ans[30] = {""};
        ss >> s;
        while (ss >> s) {
            if (s[0] != '-' || s.size() != 2||s[1]<'a'||s[1]>'z') {
                break;
            } else {
                if (type[s[1]-'a'] == 0) {
                    break;
                } else if (type[s[1]-'a'] == 1) {
                    ans[s[1] - 'a'] = s;
                } else {
                    if (ss.eof()) {
                        // 注释代码为了特判最后的一个字符串是带参数时的处理，可以不加
//                        if (ans[s[1]-'a'].size()==0){
//                            ans[s[1] - 'a'] = s;
//                        }
                        break;
                    } else {
                        std::string temp;
                        ss >> temp;
                        ans[s[1] - 'a'] = s + " " + temp;
                    }
                }
            }
        }

        std::cout << "Case " << i << ":";
        for (int j = 0; j < 26; ++j) {
            if (ans[j].size() != 0) {
                std::cout << " " << ans[j];
            }
        }
        std::cout << std::endl;
    }
    return 0;
}