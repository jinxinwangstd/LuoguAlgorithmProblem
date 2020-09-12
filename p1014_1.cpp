#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    int n = 1;
    while ((n * (n + 1) / 2) < N)
        n++;
    int idx = N - ((n - 1) * n / 2);
    if (n % 2)
        cout << (n + 1 - idx) << "/" << idx << "\n";
    else
        cout << idx << "/" << (n + 1 - idx) << "\n";
    return 0;
}