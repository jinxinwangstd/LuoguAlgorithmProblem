#include <bits/stdc++.h>

using namespace std;

unordered_map<string, set<int>> um;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, L, M;
    string w;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> L;
        while (L--) {
            cin >> w;
            um[w].insert(i);
        }
    }
    cin >> M;
    while (M--) {
        cin >> w;
        if (um.count(w)) {
            for (auto iter = um[w].begin(); iter != um[w].end(); iter++) {
                if (iter == um[w].begin())
                    cout << *iter;
                else
                    cout << " " << *iter;
            }
        }
        cout << "\n";
    }
    return 0;
}