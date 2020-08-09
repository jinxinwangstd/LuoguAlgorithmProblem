#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj_list;
vector<int> arr, fin, ind;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, u, v, len;
    cin >> N;
    adj_list.assign(N, vector<int>());
    arr.resize(N);
    fin.resize(N);
    ind.assign(N, 0);
    while (N--) {
        cin >> u >> len;
        u--;
        arr[u] = len;
        fin[u] = len;
        while (true) {
            cin >> v;
            if (!v) break;
            v--;
            adj_list[v].push_back(u);
            ind[u]++;
        }
    }
    deque<int> dq;
    for (int i = 0; i < ind.size(); i++)
        if (!ind[i])
            dq.push_back(i);
    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();
        for (int v: adj_list[u]) {
            fin[v] = max(fin[v], fin[u] + arr[v]);
            if (!(--ind[v])) 
                dq.push_back(v);
        }
    }
    cout << *max_element(fin.begin(), fin.end()) << "\n";
    return 0;
}