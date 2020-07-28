#include <bits/stdc++.h>

using namespace std;

vector<int> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    a.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int idx = 0;
    for (int i = 0; i < M; i++) {
        cin >> idx;
        cout << a[idx - 1] << "\n";
    }
    return 0;
}