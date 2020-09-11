#include <bits/stdc++.h>

using namespace std;

int L, M, u, v, res;
vector<vector<int>> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> L >> M;
    res = L + 1;
    while (M--) {
        cin >> u >> v;
        arr.push_back({u, v});
    }
    sort(arr.begin(), arr.end());
    int l = 0, r = 0;
    while (true) {
        if (r >= arr.size()) {
            res -= (arr[l][1] - arr[l][0] + 1);
            break;
        }
        if (arr[r][0] > arr[l][1]) {
            res -= (arr[l][1] - arr[l][0] + 1);
            l = r;
        }
        else {
            arr[l][1] = max(arr[l][1], arr[r][1]);
        }
        r++;
    }
    cout << res << "\n";
    return 0;
}