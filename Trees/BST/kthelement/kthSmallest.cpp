#include<bits/stdc++.h>
#include "../../tree.h"
using namespace std;

class Solution {
    public:

    /*
    
        intution: we do resursive ascending order of inorder to get the kth element.
    */
    node* kth(node *root, int &k) {
        if(root==NULL)
            return NULL;
        
        node* left=kth(root->left,k);
        if(left!=NULL)
            return left;
        k--;
        if(k==0)
            return root;
        return kth(root->right,k);
    }
    
    int kthSmallest(node* root, int k) {
        return kth(root, k)->val;
    }
};

int main() {

    return 0;
}