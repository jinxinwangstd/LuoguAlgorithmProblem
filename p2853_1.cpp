#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj_list;
vector<int> arr, colors, cows;

void dfs(int u) {
    if (!colors[u]) {
        colors[u] = 1;
        arr[u]++;
        for (int v: adj_list[u])
            dfs(v);
        colors[u] = 2;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int K, N, M, u, v;
    cin >> K >> N >> M;
    adj_list.assign(N, vector<int>());
    arr.assign(N, 0);
    colors.assign(N, 0);
    while (K--) {
        cin >> u;
        u--;
        cows.push_back(u);
    }
    while (M--) {
        cin >> u >> v;
        u--;
        v--;
        adj_list[u].push_back(v);
    }
    for (int cow: cows) {
        colors.assign(N, 0);
        dfs(cow);
    }
    int res = 0;
    for (int i = 0; i < N; i++)
        res += (arr[i] == cows.size());
    cout << res << "\n";
    return 0;
}