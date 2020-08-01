#include <bits/stdc++.h>

using namespace std;

multiset<int> ms;

int op1(int x) {
    auto iter = ms.lower_bound(x);
    return distance(ms.begin(), iter) + 1;
}

int op2(int x) {
    auto iter = next(ms.begin(), x - 1);
    return *iter;
}

int op3(int x) {
    auto iter = ms.lower_bound(x);
    if (iter == ms.begin())
        return -2147483647;
    else
        return *prev(iter);
}

int op4(int x) {
    auto iter = ms.upper_bound(x);
    if (iter == ms.end())
        return 2147483647;
    else
        return *iter;
}

void op5(int x) {
    ms.insert(x);
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    while (N) {
        N--;
        int op, x;
        cin >> op >> x;
        switch(op) {
            case 1: 
                cout << op1(x) << "\n";
                break;
            case 2:
                cout << op2(x) << "\n";
                break;
            case 3:
                cout << op3(x) << "\n";
                break;
            case 4:
                cout << op4(x) << "\n";
                break;
            case 5:
                op5(x);
        }
    }
    return 0;
}