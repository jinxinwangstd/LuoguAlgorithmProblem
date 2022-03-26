#include <bits/stdc++.h>

using namespace std;

int N, pivot;
vector<int> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    pivot = (N - 1) / 2;
    while (pivot > 0 && arr[pivot] == arr[pivot - 1])
        pivot--;
    cout << pivot << "\n";
    int cur1 = 0, cur2 = pivot;
    while (cur1 < pivot) {
        cout << arr[cur2++] << " ";
        cout << arr[cur1++] << " ";
    }
    while (cur2 < N)
        cout << arr[cur2++] << " ";
    return 0;
}