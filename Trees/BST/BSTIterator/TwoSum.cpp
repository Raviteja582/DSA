#include<bits/stdc++.h>
#include <stack>
#include "../../tree.h"
using namespace std;

class BSTIterator {
    stack<node*> st;
    bool isRev;
    public:
    /*
        rev=true-> construct reverse iterator.
        rev=false -> construct forward iterator.
    */
    BSTIterator(node* root, bool rev=false) {
        isRev=rev;
        pushAll(root);
    }

    node* next() {
        if(st.empty()) return nullptr;
        auto it = st.top();st.pop();
        if(isRev)
            pushAll(it->left);
        else
            pushAll(it->right);
        return it;
    }

    bool hasNext() {
        return !st.empty();
    }

    void pushAll(node* root) {
        if(!root) return;
        while(root) {
            st.push(root);
            if(isRev){
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return;
    }
};

class Solution {
public:
    bool findTarget(node* root, int k) {
        BSTIterator left(root), right(root, true);
        node* lh=left.next();
        node* rh=right.next();
        while(lh && rh && lh!=rh) {
            int sum = lh->val+rh->val;
            if(sum==k) return true;
            else if(sum>k) {
                rh=right.next();
            } else {
                lh=left.next();
            }
        }
        return false;
    }
};