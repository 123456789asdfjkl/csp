#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct node {
    int health;
    int attack;

    node(int h, int a) {
        health = h;
        attack = a;
    }
};

vector<node> player[2];//表示两个玩家和随从

int main() {
    int n;
    cin >> n;
    int index = 0;
    player[0].push_back(node(30, 0));
    player[1].push_back(node(30, 0));
    for (int i = 0; i < n; i++) {
        string action;
        cin >> action;
        if (action == "summon") {
            int pos, heal, att;
            cin >> pos >> att >> heal;
            player[index].insert(player[index].begin() + pos, node(heal, att));
        } else if (action == "attack") {
            int att, def;
            cin >> att >> def;
            player[index][att].health -= player[!index][def].attack;
            player[!index][def].health -= player[index][att].attack;
            if (player[index][att].health <= 0 && att != 0) {
                player[index].erase(player[index].begin() + att);
            }
            if (player[!index][def].health <= 0 && def != 0) {
                player[!index].erase(player[!index].begin() + def);
            }
        } else if (action == "end") {
            index = !index;
        }
    }

    if (player[0][0].health > 0 && player[1][0].health > 0)
        cout << "0" << endl;
    else if (player[0][0].health > 0)
        cout << "1" << endl;
    else cout << "-1" << endl;
    for (int i = 0; i < 2; i++) {
        cout << player[i][0].health << endl;
        cout << player[i].size() - 1 << " ";
        for (int j = 1; j < player[i].size(); j++) {
            cout << player[i][j].health << " ";
        }
        cout << endl;
    }
}