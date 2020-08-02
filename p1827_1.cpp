#include <bits/stdc++.h>

using namespace std;

string preorder, inorder;

void build_tree(int pl, int pr, int il, int ir) {
    if (pl > pr) return;
    char root = preorder[pl];
    int im = il;
    while (inorder[im] != root)
        im++;
    int nl = im - il, nr = ir - im;
    build_tree(pl + 1, pl + nl, il, im - 1);
    build_tree(pl + nl + 1, pr, im + 1, ir);
    cout << root;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> inorder >> preorder;
    build_tree(0, preorder.size() - 1, 0, inorder.size() - 1);
    return 0;
}