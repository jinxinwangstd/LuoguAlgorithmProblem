#include <bits/stdc++.h>

using namespace std;

vector<int> fa, ranks;
vector<vector<int>> g;

void initUnionFind(int N) {
    fa.resize(N);
    ranks.resize(N);
    for (int i = 0; i < N; i++) {
        ranks[i] = 0;
        fa[i] = i;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    g.assign(N, vector<int>());
    initUnionFind(N);
    string opt;
    int p, q;
    while (M--) {
        cin >> opt >> p >> q;
        p--;
        q--;
        if (opt == "F")
            unionSet(p, q);
        else {
            g[p].push_back(q);
            g[q].push_back(p);
        }
    }
    for (auto friends: g) {
        for (int i = 1; i < friends.size(); i++) {
            unionSet(friends[i - 1], friends[i]);
        }
    }
    int res = 0;
    for (int i = 0; i < fa.size(); i++)
        res += (fa[i] == i);
    cout << res << "\n";
    return 0;
}