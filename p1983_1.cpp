#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;
vector<vector<int>> G;
vector<int> ind, dists;
int arr[maxn];
deque<int> dq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, S;
    cin >> N >> M;
    G.assign(N, vector<int>(N, 0));
    ind.assign(N, 0);
    dists.assign(N, 0);
    while (M--) {
        cin >> S;
        for (int i = 0; i < S; i++) {
            cin >> arr[i];
            arr[i]--;
        }
        for (int u = arr[0] + 1, idx = 1; u < arr[S - 1]; u++) {
            if (u == arr[idx])
                idx++;
            else {
                for (int i = 0; i < S; i++)
                    G[u][arr[i]] = 1;
            }
        }
    }
    for (int v = 0; v < N; v++) {
        for (int u = 0; u < N; u++)
            ind[v] += G[u][v];
        if (!ind[v])
            dq.push_back(v);
    }
    while (!dq.empty()) {
        int u = dq.front(); dq.pop_front();
        for (int v = 0; v < N; v++) {
            if (G[u][v]) {
                dists[v] = max(dists[v], dists[u] + 1);
                if (!(--ind[v]))
                    dq.push_back(v);
            }
        }
    }
    cout << (*max_element(dists.begin(), dists.end())) + 1 << "\n";
    return 0;
}

/*
 * 对于输入中存在大量重复边的情况，使用邻接矩阵会比较好一些，避免重复。
 */