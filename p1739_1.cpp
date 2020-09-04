#include <bits/stdc++.h>

using namespace std;

deque<char> stk;
char c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> c) {
        if (c == '(')
            stk.push_back(c);
        else if (c == ')') {
            if (!stk.empty() && stk.back() == '(')
                stk.pop_back();
            else
                stk.push_back(c);
        }
    }
    cout << (stk.empty() ? "YES" : "NO") << "\n";
    return 0;
}