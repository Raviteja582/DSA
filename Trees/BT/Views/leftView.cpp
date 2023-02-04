#include<bits/stdc++.h>
#include <vector>
#include "../../tree.h"
using namespace std;

class Solution {
    public:

    /*
        for rightView swap the two recursive positions.
    */
    void helper(node *root, int level, vector<int> &ans) {
        if(root==nullptr) return;
        if(level==ans.size())
            ans.push_back(root->val);
        helper(root->left, level+1, ans);
        helper(root->right, level+1, ans);
        return;
    }

    vector<int> leftView(node *root) {
        vector<int> ans;
        helper(root, 0, ans);
        return ans;
    }
};

int main() {
    return 0;
}