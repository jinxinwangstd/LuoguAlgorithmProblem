#include <bits/stdc++.h>

using namespace std;

int K, N = 1, d = 1, res = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> K;
    while (d <= K) {
        res += N;
        if ((N * (N + 1) / 2) == d)
            N++;
        d++;
    }
    cout << res << "\n";
    return 0;
}