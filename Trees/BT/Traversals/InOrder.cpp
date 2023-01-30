#include<bits/stdc++.h>
#include <stack>
#include <vector>
#include "../../tree.h"
using namespace std;

class Solution {
    public:

    void inOrder_recursive(node *root) {
        if(root==nullptr)
            return;
        inOrder_recursive(root->left);
        cout<<root->val<<" ";
        inOrder_recursive(root->right);
    }

    vector<int> inOrder_iterative(node *root) {
        vector<int> ans;
        node *t=root;
        stack<node*> st;
        while(true) {
            if(t!=nullptr){
                st.push(t);
                t=t->left;
            } else {
                if(st.empty()) return ans;
                t=st.top();st.pop();
                ans.push_back(t->val);
                t=t->right;
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}