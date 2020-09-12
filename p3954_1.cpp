#include <bits/stdc++.h>

using namespace std;

int A, B, C, res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> A >> B >> C;
    res = (int)(0.2 * A + 0.3 * B + 0.5 * C);
    cout << res << "\n";
    return 0;
}