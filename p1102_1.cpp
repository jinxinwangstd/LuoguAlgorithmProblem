#include <bits/stdc++.h>

using namespace std;

unordered_map<long long, int> um;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, C;
    cin >> N >> C;
    long long res = 0;
    while (N) {
        N--;
        long long x;
        cin >> x;
        if (!C) {
            res += um.count(x) ? um[x] : 0;
        }
        else {
            res += um.count(C + x) ? um[C + x] : 0;
            res += um.count(x - C) ? um[x - C] : 0;
        }
        um[x]++;
    }
    cout << res << "\n";
    return 0;
}

/*
 * 一开始res开成int出现WA，原来是对答案的规模估计不正确，对于C=1, 有100000个1，10000个2的时候，结果可能为10^10。
 */