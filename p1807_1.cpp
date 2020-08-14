#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> adj_list;
vector<int> ind, dists;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, u, v, w;
    cin >> N >> M;
    adj_list.assign(N, vector<pair<int, int>>());
    ind.assign(N, 0);
    dists.assign(N, INT_MIN);
    while (M--) {
        cin >> u >> v >> w;
        u--;
        v--;
        adj_list[u].push_back(make_pair(v, w));
        ind[v]++;
    }
    deque<int> dq;
    for (int i = 0; i < ind.size(); i++)
        if (!ind[i] && i)
            dq.push_back(i);
    while (!dq.empty()) {
        u = dq.front();
        dq.pop_front();
        for (auto p: adj_list[u]) {
            v = p.first;
            w = p.second;
            if (!(--ind[v]) && v)
                dq.push_back(v);
        }
    }
    dq.push_back(0);
    dists[0] = 0;
    while (!dq.empty()) {
        u = dq.front();
        dq.pop_front();
        for (auto p: adj_list[u]) {
            v = p.first;
            w = p.second;
            dists[v] = max(dists[v], dists[u] + w);
            if (!(--ind[v]))
                dq.push_back(v);
        }
    }
    cout << (dists.back() == INT_MIN ? -1 : dists.back()) << "\n";
    return 0;
}