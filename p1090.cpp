#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> heap;
    while (N) {
        int a;
        cin >> a;
        heap.push(a);
        N--;
    }
    int res = 0;
    while (heap.size() > 1) {
        int a = heap.top();
        heap.pop();
        int b = heap.top();
        heap.pop();
        res += a + b;
        heap.push(a + b);
    }
    printf("%i\n", res);
    return 0;
}