#include<bits/stdc++.h>
#include "../tree.h"
using namespace std;

class Solution {
    public:
    /*
        finding predecessor & successor of a key in BST
        intution: 
            - for each node:
                i. if node->val > key, then it is possible successor and search left for smaller values > key
                ii. if node->val < key, then it is possible predecessor and search right for greater values < key
                iii. if node->val==key, then predecessor will be in left and successor will be in right. 
    */
    void findPreSuc(node* root, node*& pre, node*& suc, int key)
    {
        if(!root) return;
        if(root->val == key){
            findPreSuc(root->left, pre, suc, key);
            findPreSuc(root->right, pre, suc, key);
        }
        else if(root->val > key) {
            if(!suc)
                suc=root;
            else
                suc=suc->val<=root->val ? suc : root;
            findPreSuc(root->left, pre, suc, key);
        }
        else {
            if(!pre)
                pre=root;
            else
                pre=pre->val>=root->val ? pre : root;
            findPreSuc(root->right, pre, suc, key);
        }
    }
};

int main() {

    return 0;
}