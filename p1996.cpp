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
    nexts[prevs[x]] = nexts[x];
    prevs[nexts[x]] = prevs[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    a.resize(N + 1);
    nexts.resize(N + 1);
    prevs.resize(N + 1);
    nexts[0] = 0;
    prevs[0] = 0;
    for (int i = 1; i <= N; i++) {
        a[i] = i;
        insert_node(0, i);
    }
    int p = 1, idx = 1;
    while (true) {
        if (nexts[0] == 0) break;
        if (idx == M) {
            cout << a[p] << " ";
            p = nexts[p];
            delete_node(prevs[p]);
            idx = 1;
        }
        else {
            p = nexts[p];
            idx++;
        }
        if (p == 0) p = nexts[p];
    }
    return 0;
}
