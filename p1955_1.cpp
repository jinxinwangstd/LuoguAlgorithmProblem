#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> ids;
vector<int> p, ranks;
vector<pair<int, int>> seps;

int get_id(int x) {
    if (!ids.count(x)) {
        ids[x] = p.size();
        p.push_back(ids[x]);
        ranks.push_back(0);
    }
    return ids[x];
}

void initUnionFind(int N) {
    ranks.resize(N);
    p.resize(N);
    for (int i = 0; i < N; i++) {
        ranks[i] = 0;
        p[i] = i;
    }
}

int findSet(int x) {
    return (p[x] == x) ? x : p[x] = findSet(p[x]);
}

bool isSameSet(int u, int v) {
    return findSet(u) == findSet(v);
}

void unionSet(int u, int v) {
    if (!isSameSet(u, v)) {
        int x = findSet(u), y = findSet(v);
        if (ranks[x] > ranks[y])
            p[y] = x;
        else {
            p[x] = y;
            if (ranks[x] == ranks[y]) ranks[y]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        ids.clear();
        seps.clear();
        initUnionFind(0);
        int N;
        cin >> N;
        while (N--) {
            int i, j, e;
            cin >> i >> j >> e;
            i = get_id(i);
            j = get_id(j);
            if (e) {
                unionSet(i, j);
            }
            else {
                seps.push_back(make_pair(i, j));
            }
        }
        bool res = true;
        for (auto sep: seps) {
            if (isSameSet(sep.first, sep.second))
                res = false;
        }
        cout << (res ? "YES\n" : "NO\n");
    }
    return 0;
}