#include <bits/stdc++.h>

using namespace std;

int L, R, val, res = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> L >> R;
    for (int i = L; i <= R; i++) {
        val = i;
        while (val) {
            res += (val % 10 == 2);
            val /= 10;
        }
    }
    cout << res << "\n";
    return 0;
}