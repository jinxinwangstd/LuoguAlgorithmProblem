#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    long long l_res = 0, r_res = 0;
    int prev = 0, cur = 0, diff = 0;
    for (int i = 0; i < N; i++) {
        prev = cur;
        cur = arr[i];
        diff = prev + cur - X;
        cur -= diff > 0 ? diff : 0;
        l_res += diff > 0 ? diff : 0;
    }
    prev = 0;
    cur = 0;
    for (int i = N - 1; i >= 0; i--) {
        prev = cur;
        cur = arr[i];
        diff = prev + cur - X;
        cur -= diff > 0 ? diff : 0;
        r_res += diff > 0 ? diff : 0;
    }
    printf("%lli\n", min(l_res, r_res));
    return 0;
}