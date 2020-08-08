#include <bits/stdc++.h>

using namespace std;

unordered_multiset<string> um;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, res = 0;
    cin >> N;
    string city, state;
    while (N--) {
        cin >> city >> state;
        um.insert(city.substr(0, 2) + state);
    }
    for (auto id: um) {
        auto r_id = id.substr(2) + id.substr(0, 2);
        if (id.substr(0, 2) != id.substr(2))
            res += um.count(r_id);
    }
    cout << res / 2 << "\n";
    return 0;
}