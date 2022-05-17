/*
 * 90
 */
#include "iostream"
#include "string"
#include "tuple"
#include "vector"

using namespace std;

int main() {
    int n;
    string action;
    int life0 = 30, life1 = 30;
    int position, attack, health;
    int attacker, defender;
    int flag = 1;//表明当前玩家
    tuple<int, int, int> vi0[8], vi1[8];
    vi0[0] = make_tuple(0, 0, 30);
    vi1[0] = make_tuple(0, 0, 30);
    for (int i = 1; i < 8; ++i) {
        vi0[i] = make_tuple(-1, 0, 0);
        vi1[i] = make_tuple(-1, 0, 0);
    }
    cin >> n;
    while (n--) {
        cin.ignore();
        cin >> action;
        if (action == "summon") {
            cin >> position >> attack >> health;
            if (flag == 1) {
                if (get<0>(vi0[position]) != -1) {
                    for (int i = 7; i > position; --i) {
                        vi0[i] = vi0[i - 1];
                        if (get<0>(vi0[i]) != -1) {
                            get<0>(vi0[i]) = i;
                        }
                    }
                }
                vi0[position] = make_tuple(position, attack, health);
            } else {
                if (get<0>(vi1[position]) != -1) {
                    for (int i = 7; i > position; --i) {
                        vi1[i] = vi1[i - 1];
                        if (get<0>(vi1[i]) != -1) {
                            get<0>(vi1[i]) = i;
                        }
                    }
                }
                vi1[position] = make_tuple(position, attack, health);
            }
        } else if (action == "attack") {
            cin >> attacker >> defender;
            if (flag == 1) {
                auto temp1 = vi0[attacker];
                auto temp2 = vi1[defender];
                get<2>(temp1) -= get<1>(temp2);
                get<2>(temp2) -= get<1>(temp1);
                if (get<2>(temp1) <= 0 && attacker != 0) {
                    for (int i = attack; i <= 6; ++i) {
                        vi0[i] = vi0[i + 1];
                        if (get<0>(vi0[i]) != -1) {
                            get<0>(vi0[i]) = i;
                        }
                    }
                    vi0[7] = make_tuple(-1, 0, 0);
                } else {
                    vi0[attacker] = temp1;
                }
                if (get<2>(temp2) <= 0 && defender != 0) {
                    for (int i = defender; i <= 6; ++i) {
                        vi1[i] = vi1[i + 1];
                        if (get<0>(vi1[i]) != -1) {
                            get<0>(vi1[i]) = i;
                        }
                    }
                    vi1[7] = make_tuple(-1, 0, 0);
                } else {
                    vi1[defender] = temp2;
                }
            } else {
                auto temp1 = vi0[defender];
                auto temp2 = vi1[attacker];
                get<2>(temp1) -= get<1>(temp2);
                get<2>(temp2) -= get<1>(temp1);
                if (get<2>(temp1) <= 0 && defender != 0) {
                    for (int i = defender; i <= 6; ++i) {
                        vi0[i] = vi0[i + 1];
                        if (get<0>(vi0[i]) != -1) {
                            get<0>(vi0[i]) = i;
                        }
                    }
                    vi0[7] = make_tuple(-1, 0, 0);
                } else {
                    vi0[defender] = temp1;
                }
                if (get<2>(temp2) <= 0 && attacker != 0) {
                    for (int i = attacker; i <= 6; ++i) {
                        vi1[i] = vi1[i + 1];
                        if (get<0>(vi1[i]) != -1) {
                            get<0>(vi1[i]) = i;
                        }
                    }
                    vi1[7] = make_tuple(-1, 0, 0);
                } else {
                    vi1[attacker] = temp2;
                }
            }
        } else if (action == "end") {
            flag = -flag;
        }
    }
    if (get<2>(vi0[0]) <= 0) {
        cout << -1 << endl;
    } else if (get<2>(vi1[0]) <= 0) {
        cout << 1 << endl;
    } else if (get<2>(vi0[0]) > 0 && get<2>(vi1[0]) > 0) {
        cout << 0 << endl;
    }
    cout << get<2>(vi0[0]) << endl;
    vector<int> ans;
    for (int i = 1; i < 8; ++i) {
        if (get<0>(vi0[i]) != -1) {
            ans.push_back(get<2>(vi0[i]));
        }
    }
    cout << ans.size();
    for (int i = 0; i < ans.size(); ++i) {
        cout << " " << ans[i];
    }
    cout << endl;

    cout << get<2>(vi1[0]) << endl;
    ans.clear();
    for (int i = 1; i < 8; ++i) {
        if (get<0>(vi1[i]) != -1) {
            ans.push_back(get<2>(vi1[i]));
        }
    }
    cout << ans.size();
    for (int i = 0; i < ans.size(); ++i) {
        cout << " " << ans[i];
    }
    return 0;
}