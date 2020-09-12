#include <bits/stdc++.h>

using namespace std;

string N;
bool neg = false;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    if (N[0] == '-') {
        neg = true;
        N = N.substr(1);
    }
    reverse(N.begin(), N.end());
    int res = stoi(N);
    cout << (neg ? -res : res) << "\n";
    return 0;
}