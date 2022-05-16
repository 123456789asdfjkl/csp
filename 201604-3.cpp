#include "iostream"
#include "string"
#include "vector"

void find_dir(std::string s, std::string root, std::vector<std::string> &vi) {
    std::string temp;
    int flag = 1;   //0表示正在读文件和目录，1表示没有正在读
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '/' && flag) {
            if (!vi.empty()) {
                vi.pop_back();
            }
            i++;
            continue;
        } else if (s[i] == '.' && s[i + 1] == '/' && flag) {
            continue;
        } else if (s[i] == '/') {
            if (!temp.empty()) {
                vi.push_back(temp);
                temp.clear();
                flag = 1;
            }
            continue;
        } else {
            temp += s[i];
            flag = 0;
        }
    }
    if (!temp.empty()) {
        vi.push_back(temp);
    }
}

int main() {
    int P;
    std::string root;
    std::string temp;
    std::vector<std::string> vi;
    std::cin >> P >> root;
    std::cin.ignore();
    for (int i = 0; i < P; ++i) {
        getline(std::cin, temp);
        vi.clear();
        if (temp[0] != '/') {
            temp = root + "/" + temp;
        }
        find_dir(temp, root, vi);
        if (vi.empty()) {
            std::cout << "/" << std::endl;
            continue;
        }
        for (int j = 0; j < vi.size(); ++j) {
            std::cout << "/" << vi[j];
        }
        std::cout << std::endl;
    }
    return 0;
}