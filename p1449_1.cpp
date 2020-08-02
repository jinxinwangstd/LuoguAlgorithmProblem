#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    stack<int> nums, ops;
    int num = 0;
    char c;
    while (true) {
        cin >> c;
        if (c == '@') break;
        if (c >= '0' && c <= '9') {
            num *= 10;
            num += (c - '0');
        }
        else if (c == '.') {
            nums.push(num);
            num = 0;
        }
        else {
            int a, b;
            b = nums.top();
            nums.pop();
            a = nums.top();
            nums.pop();
            if (c == '+')
                nums.push(a + b);
            else if (c == '-')
                nums.push(a - b);
            else if (c == '*')
                nums.push(a * b);
            else 
                nums.push(a / b);
        }
    }
    cout << nums.top() << "\n";
    return 0;
}