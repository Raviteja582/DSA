#include<bits/stdc++.h>
#include <cstddef>
#include <vector>
#include "../../tree.h"

using namespace std;

class Solution {
    public:
    void preOrder_recursion(node *root){
        if(root==nullptr)
            return;
        
        cout<<root->val<<'\n';
        preOrder_recursion(root->left);
        preOrder_recursion(root->right);
    }

    vector<int> preOrder_iterative(node *root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        stack<node *> st;
        st.push(root);
        while(!st.empty()) {
            node* t=st.top(); st.pop();
            ans.push_back(t->val);
            if(t->right!=nullptr)
                st.push(t->right);
            if(t->left!=nullptr)
                st.push(t->left);
        }
        return ans;
    }
};

int main() {

    return 0;
}