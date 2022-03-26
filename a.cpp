#include <bits/stdc++.h>

using namespace std;

int T, N, digit;
string NUM;
bool hasOdd, hasEven;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> NUM;
        if (N % 2) {
            hasOdd = false;
            for (int i = 0; i < NUM.size(); i += 2) {
                digit = NUM[i] - '0';
                hasOdd = hasOdd || (digit % 2);
            }
            cout << (hasOdd ? 1 : 2) << "\n";
        }
        else {
            hasEven = false;
            for (int i = 1; i < NUM.size(); i += 2) {
                digit = NUM[i] - '0';
                hasEven = hasEven || !(digit % 2);
            }
            cout << (hasEven ? 2 : 1) << "\n";
        }
    }
    return 0;
}