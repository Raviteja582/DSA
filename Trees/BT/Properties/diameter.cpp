#include <bits/stdc++.h>
#include "../../tree.h"
using namespace std;

class Solution {
public:
    int size = 0;
    int diameterOfBinaryTree(node* root) {
        dfs(root);
        return size;
    }

    int dfs(node* root) {
        if (!root) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        size = max(size, l + r);
        return 1 + max(l, r);
    }
};