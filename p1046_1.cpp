#include <bits/stdc++.h>

using namespace std;

const int b = 30;
vector<int> arr(10);
int h, res = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 10; i++)
        cin >> arr[i];
    cin >> h;
    for (int val: arr)
        res += (h + b) >= val;
    cout << res << "\n";
    return 0;
}