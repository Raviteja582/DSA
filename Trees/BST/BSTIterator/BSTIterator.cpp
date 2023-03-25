#include<bits/stdc++.h>
#include <stack>
#include "../../tree.h"
using namespace std;

class Solution {
    stack<node*> st;
    public:
    Solution(node* r) {
        pushAll(r);
    }

    // called by the controller
    int next() {
        if(st.empty()) return INT_MAX;
        node* tmp = st.top(); st.pop();
        pushAll(tmp->right);
        return tmp->val;
    }

    // called by the controller
    bool hasNext() {
        return !st.empty();
    }

    // custom defined function
    void pushAll(node* root) {
        if(!root) return;
        while(root) {
            st.push(root);
            root=root->left;
        }
    }
};

int main() {

    return 0;
}