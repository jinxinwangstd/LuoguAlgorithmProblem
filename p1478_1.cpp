#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, S, A, B;
    cin >> N >> S >> A >> B;
    vector<pair<int, int>> apples;
    while (N) {
        int x, y;
        cin >> x >> y;
        apples.push_back(make_pair(y, x));
        N--;
    }
    sort(apples.begin(), apples.end());
    int res = 0;
    for (auto& a: apples) {
        if (a.second <= A + B && S >= a.first) {
            res++;
            S -= a.first;
        }
    }
    printf("%i\n", res);
    return 0;
}