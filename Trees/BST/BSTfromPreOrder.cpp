#include<bits/stdc++.h>
#include <vector>
#include "../tree.h"
using namespace std;

class Solution {
    public:
    /*
        for left child: in BST, all left child should < root, so upper_bound=root->val
        for right child: in BST, all right child should > root but <root's parent, so upperBound=parent->val
    */
    node* build(int &ind, int upperBound, vector<int> &pre) {
        if(ind==pre.size() || pre[ind] > upperBound) return nullptr;
        
        node* root = new node(pre[ind++]);
        root->left = build(ind, root->val, pre);
        root->right = build(ind, upperBound, pre);
        return root;
    }

    node* bstFromPreorder(vector<int>& preorder) {
        int ind=0;
        // passing upper_bound as INT_MAX, so root will fit the tree and corresponding right nodes will fit.
        return build(ind, INT_MAX, preorder);    
    }
};

int main() {

    return 0;
}