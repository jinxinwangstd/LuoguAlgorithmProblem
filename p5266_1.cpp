#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> um;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    while (N) {
        N--;
        int op;
        cin >> op;
        if (op == 4) {
            cout << um.size() << "\n";
        }
        else {
            string name;
            cin >> name;
            if (op == 1) {
                int score;
                cin >> score;
                um[name] = score;
                cout << "OK\n";
            }
            else if (op == 2) {
                if (um.count(name))
                    cout << um[name] << "\n";
                else
                    cout << "Not found\n";
            }
            else {
                if (um.count(name)) {
                    um.erase(name);
                    cout << "Deleted successfully\n";
                }
                else
                    cout << "Not found\n";
            }
        }
    }
    return 0;
}