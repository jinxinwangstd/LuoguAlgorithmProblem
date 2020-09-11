#include <bits/stdc++.h>

using namespace std;

const double esp = 1e-10;
double sum = 0.0;
int n = 0, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> k;
    while (sum - k <= esp) {
        n++;
        sum += 1.0 / n;
    }
    cout << n << "\n";
    return 0;
}