#include <bits/stdc++.h>

using namespace std;

string inorder, postorder;

void build_tree(int pl, int pr, int il, int ir) {
    if (pl > pr) return;
    char root = postorder[pr];
    int im = il;
    while (inorder[im] != root)
        im++;
    int nl = im - il, nr = ir - im;
    cout << root;
    build_tree(pl, pl + nl - 1, il, im - 1);
    build_tree(pl + nl, pr - 1, im + 1, ir);
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> inorder >> postorder;
    build_tree(0, postorder.size() - 1, 0, inorder.size() - 1);
    return 0;
}