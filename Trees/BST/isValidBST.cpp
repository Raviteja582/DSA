#include<bits/stdc++.h>
#include "../tree.h"
using namespace std;

class Solution {
    public:
    /*
        intution: assign upper & lower bound to each node.
    */
    bool isValidBST(node* root, int lb, int ub) {
        if(!root) return true;
        if(root->val > lb && root->val < ub) {
            return isValidBST(root->left, lb, root->val) && isValidBST(root->right, root->val, ub);
        }
        return false;
    }
    bool isValidBST(node* root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }
};

int main() {

    return 0;
}