#include <bits/stdc++.h>

using namespace std;

vector<int> pushed, poped;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Q;
    cin >> Q;
    while (Q) {
        Q--;
        int N;
        cin >> N;
        pushed.resize(N);
        poped.resize(N);
        for (int i = 0; i < N; i++)
            cin >> pushed[i];
        for (int i = 0; i < N; i++)
            cin >> poped[i];
        stack<int> st;
        for (int i = 0, j = 0; i < N; i++) {
            st.push(pushed[i]);
            while (!st.empty() && st.top() == poped[j]) {
                st.pop();
                j++;
            }
        }
        cout << (st.empty() ? "Yes\n" : "No\n");
    }
    return 0;
}

/**
 * Pushed是无序的
 */