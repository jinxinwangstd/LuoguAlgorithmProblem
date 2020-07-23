#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> arr(M);
    while (M) {
        int p, a;
        cin >> p >> a;
        arr.push_back(make_pair(p, a));
        M--;
    }
    sort(arr.begin(), arr.end());
    int res = 0, idx = 0;
    while (N) {
        res += arr[idx].first * (arr[idx].second > N ? N : arr[idx].second);
        N -= arr[idx].second > N ? N : arr[idx].second;
        idx++;
    }
    printf("%i\n", res);
    return 0;
}