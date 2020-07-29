#include <bits/stdc++.h>

using namespace std;

unordered_set<int> us;
deque<int> dq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int M, N;
    cin >> M >> N;
    int res = 0;
    while (N) {
        N--;
        int x;
        cin >> x;
        if (us.count(x)) continue;
        if (dq.size() == M) {
            int y = dq.front();
            dq.pop_front();
            us.erase(y);
        }
        dq.push_back(x);
        us.insert(x);
        res++;
    }
    cout << res;
    return 0;
}