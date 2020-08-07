#include <bits/stdc++.h>

using namespace std;

unordered_set<int> us;
vector<int> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        us.clear();
        a.clear();
        int N, x;
        cin >> N;
        while (N--) {
            cin >> x;
            if (!us.count(x)) {
                us.insert(x);
                a.push_back(x);
            }
        }
        for (auto num: a)
            cout << num << " ";
        cout << "\n";
    }
    return 0;
}