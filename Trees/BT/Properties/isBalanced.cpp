#include <bits/stdc++.h>
#include "../../tree.h"
using namespace std;


class Solution {
public:
    bool isBalanced(node* root) {
        if(!root){
            return true;
        }
        if(abs(height(root->left)-height(root->right))>=2){
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int height(node* root){
        if(!root)
            return 0;

        return 1+ max(height(root->left),height(root->right));
    }
};