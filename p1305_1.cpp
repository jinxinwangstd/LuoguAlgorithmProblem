#include <bits/stdc++.h>

using namespace std;

vector<char> a;
unordered_map<char, int> idx;
vector<int> lefts, rights;
int counter;

void preorder(int x) {
    if (x == 0) return;
    cout << a[x];
    preorder(lefts[x]);
    preorder(rights[x]);
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    a.resize(N + 1);
    lefts.resize(N + 1);
    rights.resize(N + 1);
    a.push_back('*');
    idx['*'] = 0;
    counter = 0;
    string s;
    while (N) {
        N--;
        cin >> s;
        char p = s[0], c1 = s[1], c2 = s[2];
        if (!idx.count(p)) {
            idx[p] = ++counter;
            a[counter] = p;
        }
        if (!idx.count(c1)) {
            idx[c1] = ++counter;
            a[counter] = c1;
        }
        if (!idx.count(c2)) {
            idx[c2] = ++counter;
            a[counter] = c2;
        }
        lefts[idx[p]] = idx[c1];
        rights[idx[p]] = idx[c2];
    }
    preorder(1);
    return 0;
}

/*
 * By default, the first node we met is the root node.
 */