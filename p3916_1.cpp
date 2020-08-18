#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G1, G2;
vector<int> pre, lowlink, scc_idx, ind, max_node;
int scc_count, dfs_clock;
stack<int> stk;
deque<int> dq;

void dfs(int u) {
    pre[u] = lowlink[u] = ++dfs_clock;
    stk.push(u);
    for (int v: G1[u]) {
        if (!pre[v]) {
            dfs(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        } else if (scc_idx[v] < 0) {
            lowlink[u] = min(lowlink[u], pre[v]);
        }
    }
    if (lowlink[u] == pre[u]) {
        while (true) {
            int x = stk.top(); stk.pop();
            scc_idx[x] = scc_count;
            if (x == u) break;
        }
        scc_count++;
    }
}

void find_scc(int n) {
    dfs_clock = scc_count = 0;
    pre.assign(n, 0);
    lowlink.assign(n, 0);
    scc_idx.assign(n, -1);
    for (int i = 0; i < n; i++)
        if (!pre[i])
            dfs(i);
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, u, v;
    cin >> N >> M;
    G1.assign(N, vector<int>());
    while (M--) {
        cin >> u >> v;
        u--;
        v--;
        G1[u].push_back(v);
    }
    find_scc(N);
    G2.assign(scc_count, vector<int>());
    ind.assign(scc_count, 0);
    max_node.assign(scc_count, -1);
    for (int u = 0; u < N; u++) {
        max_node[scc_idx[u]] = max(max_node[scc_idx[u]], u);
        for (int v: G1[u]) {
            if (scc_idx[u] != scc_idx[v]) {
                G2[scc_idx[v]].push_back(scc_idx[u]);
                ind[scc_idx[u]]++;
            }
        }
    }
    for (int i = 0; i < scc_count; i++)
        if (!ind[i])
            dq.push_back(i);
    while (!dq.empty()) {
        int u = dq.front(); dq.pop_front();
        for (int v: G2[u]) {
            max_node[v] = max(max_node[v], max_node[u]);
            if (!(--ind[v])) 
                dq.push_back(v);
        }
    }
    for (int i = 0; i < N; i++)
        cout << max_node[scc_idx[i]] + 1 << " ";
    cout << "\n";
    return 0;
}