#include<bits/stdc++.h>
#include <vector>
#include "../../tree.h"
using namespace std;

class Solution {
    public:

    vector<int> preOrder(node* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<node*> st;
        node* curr = root;
        while(true) {
            if(curr->left==nullptr) {
                ans.push_back(curr->val);
                curr=curr->right;
            } else {
                node* ptr = curr->left;
                while(ptr->right && ptr->right!=curr) {
                    ptr=ptr->right;
                }
                if(ptr->right==nullptr) {
                    ptr->right=curr;
                    ans.push_back(curr->val);
                    curr=curr->left;
                }
                else {
                    ptr->right=nullptr;
                    curr=curr->right;
                }
            }
        } 
        return ans;
    }

    vector<int> inOrder(node* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<node*> st;
        node* curr = root;
        while(true) {
            if(curr->left==nullptr) {
                ans.push_back(curr->val);
                curr=curr->right;
            } else {
                node* ptr = curr->left;
                while(ptr->right && ptr->right!=curr) {
                    ptr=ptr->right;
                }
                if(ptr->right==nullptr) {
                    ptr->right=curr;
                    curr=curr->left;
                }
                else {
                    ptr->right=nullptr;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        } 
        return ans;
    }
};

int main() {

    return 0;
}