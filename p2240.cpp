#include <bits/stdc++.h>
using namespace std;
class Compare {
public:
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return (double)a.second / a.first < (double)b.second / b.first;
    }
};
int main() {
    int N, T;
    cin >> N >> T;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> heap;
    while (N) {
        int m, v;
        cin >> m >> v;
        heap.push(make_pair(m, v));
        N--;
    }
    double res = 0;
    while (!heap.empty() && T) {
        int m = heap.top().first, v = heap.top().second;
        heap.pop();
        res += m > T ? v * (T / (double)m) : v;
        T -= m > T ? T : m;
    }
    printf("%.2f\n", res);
    return 0;
}