#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj_list;
vector<int> colors, dists;

void dfs(int u) {
    if (!colors[u]) {
        colors[u] = 1;
        cout << u + 1 << " ";
        for (int v: adj_list[u])
            dfs(v);
        colors[u] = 2;
    }
}

void bfs(int start) {
    deque<int> dq;
    dists[start] = 0;
    dq.push_back(start);
    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();
        cout << u + 1 << " ";
        for (int v: adj_list[u]) {
            if (dists[v] < 0) {
                dists[v] = dists[u] + 1;
                dq.push_back(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, u, v;
    cin >> N >> M;
    adj_list.assign(N, vector<int>());
    colors.assign(N, 0);
    dists.assign(N, -1);
    while (M--) {
        cin >> u >> v;
        u--;
        v--;
        adj_list[u].push_back(v);
    }
    for (int i = 0; i < N; i++)
        sort(adj_list[i].begin(), adj_list[i].end());
    dfs(0);
    cout << "\n";
    bfs(0);
    cout << "\n";
    return 0;
}