#include <bits/stdc++.h>

using namespace std;

long long a, b, c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> c;
    if (a * a > b * c)
        cout << "Alice\n";
    else
        cout << "Bob\n";
    return 0;
}