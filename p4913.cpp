#include <bits/stdc++.h>

using namespace std;

vector<int> a, lefts, rights;

int dfs(int x, int d) {
    if (x == 0) return d - 1;
    return max(dfs(lefts[x], d + 1), dfs(rights[x], d + 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    a.resize(N + 1);
    lefts.resize(N + 1);
    rights.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        int l, r;
        cin >> l >> r;
        lefts[i] = l;
        rights[i] = r;
    }
    cout << dfs(1, 1);
    return 0;
}