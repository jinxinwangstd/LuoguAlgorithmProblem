#include <bits/stdc++.h>

using namespace std;

string pre, post;

long long count(int pre_l, int pre_r, int post_l, int post_r) {
    if (pre_l > pre_r)
        return 1;
    if (pre[pre_l] != post[post_r])
        return 0;
    long long res = 0;
    int len = pre_r - pre_l + 1, l_len, r_len;
    int pre_ll, pre_lr, post_ll, post_lr;
    int pre_rl, pre_rr, post_rl, post_rr;
    for (l_len = 0; l_len <= len - 1; l_len++) {
        r_len = len - 1 - l_len;
        pre_ll = pre_l + 1;
        pre_lr = pre_ll + l_len - 1;
        post_ll = post_l;
        post_lr = post_ll + l_len - 1;
        pre_rl = pre_lr + 1;
        pre_rr = pre_r;
        post_rl = post_lr + 1;
        post_rr = post_rl + r_len - 1;
        long long l_res = count(pre_ll, pre_lr, post_ll, post_lr);
        long long r_res = count(pre_rl, pre_rr, post_rl, post_rr);
        res += l_res * r_res;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> pre >> post;
    cout << count(0, pre.size() - 1, 0, post.size() - 1) << "\n";
    return 0;
}