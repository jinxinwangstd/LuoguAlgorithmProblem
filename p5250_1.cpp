#include <bits/stdc++.h>

using namespace std;

set<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    while (N) {
        N--;
        int op, len;
        cin >> op >> len;
        if (op == 1) {
            if (s.count(len))
                cout << "Already Exist\n";
            else
                s.insert(len);
        }
        else {
            if (s.empty()) {
                cout << "Empty\n";
                continue;
            }
            int res = 0;
            auto r = s.lower_bound(len);
            auto l = s.end();
            if (r != s.begin())
                l = prev(r);
            if (l == s.end() || r == s.end())
                res = (l == s.end() ? *r : *l);
            else 
                res = ((abs(*l - len) <= abs(*r - len)) ? *l : *r);
            cout << res << "\n";
            s.erase(res);
        }
    }
    return 0;
}