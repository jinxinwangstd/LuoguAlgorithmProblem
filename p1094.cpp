#include <bits/stdc++.h>

using namespace std;

int main() {
    int W, G;
    cin >> W >> G;
    vector<int> arr(G);
    for (int i = 0; i < G; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int l = 0, r = G - 1, res = 0;
    while (l < r) {
        if (arr[l] + arr[r] > W) {
            r--;
        } else {
            r--;
            l++;
        }
        res++;
    }
    if (l == r)
        res++;
    printf("%i\n", res);
    return 0;
}