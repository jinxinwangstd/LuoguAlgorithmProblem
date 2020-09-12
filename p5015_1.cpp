#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int res = 0;
    while (cin >> s)
        res += s.size();
    cout << res << "\n";
    return 0;
}