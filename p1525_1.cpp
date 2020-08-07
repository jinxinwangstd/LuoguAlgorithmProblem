#include <bits/stdc++.h>

using namespace std;

vector<int> fa, ranks;
vector<vector<int>> arr;
vector<vector<int>> g;

void initUnionFind(int N) {
    fa.resize(N);
    ranks.resize(N);
    for (int i = 0; i < N; i++) {
        fa[i] = i;
        ranks[i] = 0;
    }
}

int findSet(int x) {
    if (fa[x] == x) return x;
    return fa[x] = findSet(fa[x]);
}

bool isSameSet(int u, int v) {
    return findSet(u) == findSet(v);
}

void unionSet(int u, int v) {
    if (!isSameSet(u, v)) {
        int x = findSet(u), y = findSet(v);
        if (ranks[x] > ranks[y])
            fa[y] = x;
        else {
            fa[x] = y;
            if (ranks[x] == ranks[y]) ranks[y]++;
        }
    }
}

bool compare(const vector<int>& a, const vector<int>& b) {
    return a[2] > b[2];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, a, b, c;
    cin >> N >> M;
    initUnionFind(N);
    g.assign(N, vector<int>());
    while (M--) {
        cin >> a >> b >> c;
        a--;
        b--;
        arr.push_back({a, b, c});
    }
    sort(arr.begin(), arr.end(), compare);
    for (auto sep: arr) {
        if (isSameSet(sep[0], sep[1])) {
            cout << sep[2] << "\n";
            return 0;
        }
        if (g[sep[0]].empty())
            g[sep[0]].push_back(sep[1]);
        else
            unionSet(g[sep[0]][0], sep[1]);
        if (g[sep[1]].empty())
            g[sep[1]].push_back(sep[0]);
        else
            unionSet(g[sep[1]][0], sep[0]);
    }
    cout << "0\n";
    return 0;
}