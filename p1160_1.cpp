#include <bits/stdc++.h>

using namespace std;

vector<int> a, nexts, prevs;

void insert_node(int i, int x) {
    prevs[x] = prevs[i];
    prevs[i] = x;
    nexts[x] = i;
    nexts[prevs[x]] = x;
}

void delete_node(int x) {
    prevs[nexts[x]] = prevs[x];
    nexts[prevs[x]] = nexts[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N;
    a.resize(N + 1);
    nexts.resize(N + 1);
    prevs.resize(N + 1);
    for (int i = 0; i <= N; i++)
        a[i] = i;
    nexts[0] = 0;
    prevs[0] = 0;
    insert_node(0, 1);
    for (int i = 2; i <= N; i++) {
        int k, p;
        cin >> k >> p;
        if (p == 0)
            insert_node(k, i);
        else
            insert_node(nexts[k], i);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        if (a[x] > 0)
            delete_node(x);
        a[x] = 0;
    }
    int p = 0;
    while (p = nexts[p])
        cout << a[p] << " ";
    return 0;
}