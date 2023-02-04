#include <bits/stdc++.h>
#include "../../tree.h"
using namespace std;


class Solution {
public:
    int maxi = INT_MIN;

    int solve(node* root) {
        if(!root) return 0;

        int lmax = max(0, solve(root->left));
        int rmax = max(0, solve(root->right));
        
        maxi=max(maxi, lmax+rmax+root->val);
        return root->val + max(lmax, rmax);
    }


    int maxPathSum(node* root) {
        solve(root);
        return maxi;
    }
};