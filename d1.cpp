#include <bits/stdc++.h>

using namespace std;

int N, res;
vector<int> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    res = (N - 1) / 2;
    cout << res << "\n";
    int cur1 = 0, cur2 = res;
    while (cur1 < res) {
        cout << arr[cur2] << " ";
        cur2++;
        cout << arr[cur1] << " ";
        cur1++;
    }
    while (cur2 < N) {
        cout << arr[cur2] << " ";
        cur2++;
    }
    return 0;
}