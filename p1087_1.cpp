#include <bits/stdc++.h>

using namespace std;

vector<char> arr;
int N;
char digit;

char postOrder(int x) {
    if (arr[x] == ' ') {
        char l = postOrder(x << 1);
        char r = postOrder((x << 1) + 1);
        arr[x] = (l == r) ? l : 'F';
    }
    cout << arr[x];
    return arr[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    arr.assign(1 << (N + 1), ' ');
    for (int i = (1 << N); i < arr.size(); i++) {
        cin >> digit;
        arr[i] = (digit == '1') ? 'I' : 'B';
    }
    postOrder(1);
    return 0;
}