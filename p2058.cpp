#include <bits/stdc++.h>

using namespace std;

int P = 86400;
deque<vector<int>> dq;
unordered_map<int, int> um;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    while (N) {
        N--;
        int t, k;
        cin >> t >> k;
        vector<int> last(k + 1);
        last[0] = t;
        for (int i = 1; i <= k; i++) {
            cin >> last[i];
            um[last[i]]++;
        }
        dq.push_back(last);
        while (!dq.empty()) {
            vector<int> first = dq.front();
            if (first[0] > (t - P)) break;
            for (int i = 1; i < first.size(); i++) {
                um[first[i]]--;
                if (um[first[i]] == 0)
                    um.erase(first[i]);
            }
            dq.pop_front();
        }
        cout << um.size() << "\n";
    }
    return 0;
}