#include <bits/stdc++.h>

using namespace std;

vector<int> tree, a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    N = 1 << N;
    a.resize(N);
    tree.resize(N << 1);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        tree[N + i] = i;
    }
    while (N) {
        for (int i = N / 2; i < N; i++)
            tree[i] = a[tree[i * 2]] > a[tree[i * 2 + 1]] ? tree[i * 2] : tree[i * 2 + 1];
        N /= 2;
    }
    int res = 0;
    if (tree[1] == tree[2])
        res = tree[3];
    else
        res = tree[2];
    cout << res + 1 << "\n";
    return 0;
}