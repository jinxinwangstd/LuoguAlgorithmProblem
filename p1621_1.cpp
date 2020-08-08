#include <bits/stdc++.h>

using namespace std;

vector<int> fa, ranks, primes, muls;
int numSet;

void initUnionFind(int N) {
    numSet = N;
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
        numSet--;
    }
}

void gen_primes(int n) {
    int i, j;
    long long k;
    vector<bool> mk(n + 1, false);
    for (i = 2, k = 4; i <= n; k += i + i + 1, i++) {
        if (!mk[i]) {
            primes.push_back(i);
            if (k <= n) {
                for (j = k; j <= n; j += i)
                    mk[j] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, p, idx;
    cin >> a >> b >> p;
    gen_primes(b);
    muls.assign(primes.size(), -1);
    initUnionFind(b - a + 1);
    idx = distance(primes.begin(), lower_bound(primes.begin(), primes.end(), p));
    for (int i = idx; i < primes.size(); i++) {
        if (primes[i] >= p) {
            for (int j = primes[i]; j <= b; j += primes[i]) {
                if (j >= a) {
                    if (muls[i] > 0)
                        unionSet(j - a, muls[i] - a);
                    else
                        muls[i] = j;
                }
            }
        }
    }
    cout << numSet << "\n";
    return 0;
}