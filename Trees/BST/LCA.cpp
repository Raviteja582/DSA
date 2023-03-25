#include<bits/stdc++.h>
#include "../tree.h"
using namespace std;

class Solution {
    public:
    /*
        intution: if the root is in between the two nodes, then it is LCA
        else root->val < mini, then search on right
        else root->val > maxi, then search on left.
    */
    node* lowestCommonAncestor(node* root,node* p,node* q) {
        if(root==nullptr) return root;
        
        // checking for one of the given node
        if(root->val==p->val || root->val == q->val) return root;

        // checking for out of range
        int mini = min(p->val, q->val);
        int maxi = max(p->val, q->val);
        
        if(root->val > maxi)
            return lowestCommonAncestor(root->left, p, q);
        else if(root->val<mini)
            return lowestCommonAncestor(root->right, p, q);
        else {
            node *left=lowestCommonAncestor(root->left, p, q); 
            node *right=lowestCommonAncestor(root->right, p, q);
            if(left && right) return root;
            if(left && !right) return left;
            if(right && !left) return right;
            return nullptr;
        }
    }
};

int main() {

    return 0;
}