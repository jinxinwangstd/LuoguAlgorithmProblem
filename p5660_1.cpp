#include <bits/stdc++.h>

using namespace std;

const int a = 1;
string s;
int val, res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    val = stoi(s, 0, 2);
    res = 0;
    while (val) {
        res += val & a;
        val >>= 1;
    }
    cout << res << "\n";
    return 0;
}