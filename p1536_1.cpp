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

int numSet() {
    int res = 0;
    for (int i = 0; i < p.size(); i++)
        res += p[i] == i;
    return res;
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
    while (true) {
        int N, M;
        cin >> N >> M;
        if (!N) break;
        initUnionFind(N);
        while (M) {
            M--;
            int u, v;
            cin >> u >> v;
            unionSet(u - 1, v - 1);
        }
        cout << numSet() - 1 << "\n";
    }
    return 0;
}

/*
 * 如果需要多次声明UnionFind，使用OOP写法可能会导致MLE。
 * 所以还是应该采用数据与方法分离的写法。
 */
