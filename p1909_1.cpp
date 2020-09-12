#include <bits/stdc++.h>

using namespace std;

int N, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int res = INT_MAX;
    cin >> N;
    for (int i = 0; i < 3; i++) {
        cin >> a >> b;
        res = min(res, ((int)ceil(N / (double)a)) * b);
    }
    cout << res << "\n";
    return 0;
}