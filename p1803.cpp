#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> contests;
    while (N) {
        int a, b;
        cin >> a >> b;
        contests.push_back(make_pair(a, b));
        N--;
    }
    sort(contests.begin(), contests.end(), compare);
    int res = 0, t = 0;
    for (auto c: contests) {
        if (c.first >= t) {
            res++;
            t = c.second;
        }
    }
    printf("%i\n", res);
    return 0;
}