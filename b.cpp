#include <bits/stdc++.h>

using namespace std;

int T, X;
vector<long long> arr1, arr2, arr3;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    arr1.push_back(0);
    arr1.push_back(1);
    arr2.push_back(0);
    arr2.push_back(1);
    arr3.push_back(0);
    int idx = 1, cur1, cur2, cur3;
    while (true) {
        cur1 = arr1[idx];
        cur2 = arr2[idx];
        if (arr1.back() < cur2) {
            arr1.push_back(cur2);
            arr2.push_back(cur2 * 2);
        }
        if (arr1.back() < cur2 + 1) {
            arr1.push_back(cur2 + 1);
            arr2.push_back(cur2 * 2 + 1);
        }
        cur3 = arr3.back();
        cur3 += (cur2 + 1) * cur2 / 2;
        if (cur3 > 1e18 || cur3 < arr3.back())
            break;
        arr3.push_back(cur3);
        idx++;
    }
    for (int i = 0; i < 100; i++)
        cout << arr1[i] << " " << arr2[i] << " " << arr3[i] << "\n";
    cin >> T;
    while (T--) {
        cin >> X;
        int idx = distance(arr3.begin(), upper_bound(arr3.begin(), arr3.end(), X));
        cout << idx - 1 << "\n";
    }
    return 0;
}