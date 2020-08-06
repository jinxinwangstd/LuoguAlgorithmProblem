#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> um;
vector<string> a;
vector<int> p;

void initUnionFind(int N) {
    p.resize(N);
    for (int i = 0; i < N; i++) {
        p[i] = i;
    }
}

void addSet() {
    p.push_back(p.size());
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
        p[y] = x;
    }
}

int get_id(const string& s) {
    if (!um.count(s)) {
        um[s] = a.size();
        a.push_back(s);
        addSet();
    }
    return um[s];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    vector<int> rel;
    while (true) {
        cin >> s;
        if (s[0] == '?') break;
        if (s[0] == '#') {
            for (int i = 1; i < rel.size(); i++)
                unionSet(rel[0], rel[i]);
            rel.clear();
        }
        rel.push_back(get_id(s.substr(1)));
    }
    for (int i = 1; i < rel.size(); i++)
        unionSet(rel[0], rel[i]);
    rel.clear();
    do {
        string name = s.substr(1);
        string anc = a[findSet(um[name])];
        cout << name << " " << anc << "\n";
        cin >> s;
    } while (s[0] != '$');
    return 0;
}