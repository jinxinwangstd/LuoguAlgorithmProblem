#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> Ts(N);
    for (int i = 0; i < N; i++) {
        cin >> Ts[i].first;
        Ts[i].second = i + 1;
    }
    sort(Ts.begin(), Ts.end());
    double res = 0;
    for (int i = 0; i < N; i++) {
        printf("%i ", Ts[i].second);
        res += Ts[i].first * (N - i - 1) / (double)N;
    }
    printf("\n%.2f\n", res);
    return 0;
}