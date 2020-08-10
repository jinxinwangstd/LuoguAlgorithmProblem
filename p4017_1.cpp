#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj_list;
vector<int> ind, outd, arr;
int mod = 80112002;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, u, v;
    cin >> N >> M;
    adj_list.assign(N, vector<int>());
    ind.assign(N, 0);
    outd.assign(N, 0);
    arr.assign(N, 0);
    while (M--) {
        cin >> u >> v;
        u--;
        v--;
        adj_list[u].push_back(v);
        ind[v]++;
        outd[u]++;
    }
    deque<int> dq;
    for (int i = 0; i < ind.size(); i++) {
        if (!ind[i]) {
            arr[i] = 1;
            dq.push_back(i);
        }
    }
    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();
        for (int v: adj_list[u]) {
            arr[v] += arr[u];
            arr[v] %= mod;
            if (!(--ind[v]))
                dq.push_back(v);
        }
    }
    int res = 0;
    for (int i = 0; i < outd.size(); i++) {
        if (!outd[i]) {
            res += arr[i];
            res %= mod;
        }
    }
    cout << res << "\n";
    return 0;
}