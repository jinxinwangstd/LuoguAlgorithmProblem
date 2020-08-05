#include <bits/stdc++.h>

using namespace std;

int P = 131;
vector<unsigned long long> hs;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    string s;
    while (N) {
        N--;
        unsigned long long h = 0;
        cin >> s;
        for (auto ch: s) {
            h = h * P + (ch - '0' + 1);
        }
        hs.push_back(h);
    }
    sort(hs.begin(), hs.end());
    int res = 1;
    for (int i = 1; i < hs.size(); i++)
        res += hs[i] != hs[i - 1];
    cout << res << "\n";
    return 0;
}