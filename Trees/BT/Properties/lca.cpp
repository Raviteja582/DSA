#include <bits/stdc++.h>
#include "../../tree.h"

class Solution {
public:
    node* lowestCommonAncestor(node* root, node* p, node* q) {
        if(!root) return root;
        if(root==p || root==q) return root;

        node* left = lowestCommonAncestor(root->left, p, q);
        node* right = lowestCommonAncestor(root->right, p, q);

        if(left && right) return root;
        else if(!left && right) return right;
        else if(left && !right) return left;
        return left;
   }
};