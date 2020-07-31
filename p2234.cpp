#include <bits/stdc++.h>

using namespace std;

set<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, x, res = 0;
    set<int>::iterator l, r;
    cin >> N;
    while (N) {
        N--;
        cin >> x;
        l = s.end(), r = s.end();
        if (s.empty()) {
            res += abs(x);
            s.insert(x);
            continue;
        }
        r = s.lower_bound(x);
        if (r != s.begin())
            l = prev(r);
        res += min(l != s.end() ? abs(*l - x) : INT_MAX, r != s.end() ? abs(*r - x) : INT_MAX);
        s.insert(x);
    }
    cout << res << "\n";
    return 0;
}