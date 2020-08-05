#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> um;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        um[a] = i;
    }
    int Q;
    cin >> Q;
    while (Q) {
        Q--;
        int m;
        cin >> m;
        cout << (um.count(m) ? um[m] : 0) << "\n";
    }
    return 0;
}