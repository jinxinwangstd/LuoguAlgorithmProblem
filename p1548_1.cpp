#include <bits/stdc++.h>

using namespace std;

int N, M, num, res1 = 0, res2 = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            num = (N - i + 1) * (M - j + 1);
            if (i == j)
                res1 += num;
            else
                res2 += num;
        }
    }
    cout << res1 << " " << res2 << "\n";
    return 0;
}