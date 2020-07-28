#include <bits/stdc++.h>

using namespace std;

vector<unordered_map<int, int>> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    a.resize(N);
    int op, i, j, k;
    while (Q) {
        Q--;
        cin >> op >> i >> j;
        i--;
        j--;
        if (op == 1) {
            cin >> k;
            if (k > 0)
                a[i][j] = k;
            else
                a[i].erase(j);
        }
        else {
            cout << a[i][j] << "\n";
        }
    }
    return 0;
}