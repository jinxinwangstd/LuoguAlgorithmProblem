#include <bits/stdc++.h>

using namespace std;

int N, val;
set<int> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    while (N--) {
        cin >> val;
        st.insert(val);
    }
    cout << st.size() << "\n";
    for (int elem: st)
        cout << elem << " ";
    cout << "\n";
    return 0;
}