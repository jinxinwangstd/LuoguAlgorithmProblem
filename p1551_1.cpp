#include <bits/stdc++.h>

using namespace std;

vector<int> p, ranks;

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
        if (ranks[x] > ranks[y]) {
            p[y] = x;
        } 
        else {
            p[x] = y;
            if (ranks[x] == ranks[y]) ranks[y]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, P;
    cin >> N >> M >> P;
    initUnionFind(N);
    while (M) {
        M--;
        int u, v;
        cin >> u >> v;
        unionSet(u - 1, v - 1);
    }
    while (P) {
        P--;
        int u, v;
        cin >> u >> v;
        cout << (isSameSet(u - 1, v - 1) ? "Yes\n" : "No\n");
    }
    return 0;
}