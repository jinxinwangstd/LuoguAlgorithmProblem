#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    vector<int> single(s.size(), 1);
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[')
            st.push(i);
        else {
            if (!st.empty()) {
                if (s[i] == ')' && s[st.top()] == '(' || s[i] == ']' && s[st.top()] == '[') {
                    single[i] = 0;
                    single[st.top()] = 0;
                    st.pop();
                }
            }
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (single[i]) {
            if (s[i] == '(' || s[i] == ')')
                cout << "()";
            else
                cout << "[]";
        }
        else {
            cout << s[i];
        }
    }
    return 0;
}

/*
 * 右括号不应该进栈，因为中间有右括号不影响左右括号配对。但如果中间有不同的左括号则会影响匹配。
 * Input: (((])[[(]]]](
 * AC:()()([])[][]()[][][][]()
 * WA:()()([])[[()]][][]()
 */