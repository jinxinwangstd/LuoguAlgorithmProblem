#include <bits/stdc++.h>

using namespace std;

vector<int> lefts, rights, depths;
int depth, width, u, v, ud, vd, anc, ancd;

void dfs(int x, int d) {
    if (!x) return;
    if (x == u) ud = d;
    if (x == v) vd = d;
    if (x == anc) ancd = d;
    depths[d]++;
    depth = max(depth, d);
    dfs(lefts[x], d + 1);
    dfs(rights[x], d + 1);
    return;
}

int lca(int root, int u, int v) {
    if (!root) return 0;
    if (root == u || root == v)
        return root;
    int l = lca(lefts[root], u, v);
    int r = lca(rights[root], u, v);
    if (l && r)
        return root;
    return l ? l : r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    lefts.assign(N + 1, 0);
    rights.assign(N + 1, 0);
    depths.assign(N + 1, 0);
    depth = 0;
    width = 0;
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        if (!lefts[x])
            lefts[x] = y;
        else
            rights[x] = y;
    }
    cin >> u >> v;
    anc = lca(1, u, v);
    dfs(1, 0);
    cout << depth + 1 << "\n";
    for (auto w: depths)
        width = max(width, w);
    cout << width << "\n";
    cout << (ud - ancd) * 2 + (vd - ancd) << "\n";
    return 0;
}
