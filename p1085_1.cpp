#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> arr(7);
int a, b;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1; i <= 7; i++) {
        cin >> a >> b;
        arr[i] = make_pair(a + b, i);
    }
    sort(arr.begin(), arr.end(), compare);
    if (arr[0].first <= 8)
        cout << 0 << "\n";
    else
        cout << arr[0].second << "\n";
    return 0;
}