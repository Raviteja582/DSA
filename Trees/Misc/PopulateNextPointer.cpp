#include<bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node *left, *right, *next;
    node():val(-1), left(nullptr), right(nullptr), next(nullptr){}
    node(int x):val(x){}
};

class Solution {
    public:
    node* connect(node* root) {
        if(!root) return root;
        node *curr=root;
        while(curr) {
            node* tmp = nullptr;
            while(curr) {
                if(curr->left) {
                    if(curr->right) {
                        curr->left->next=curr->right;
                    } else {
                        curr->left->next = findLevelNext(curr->next);
                    }
                    if(!tmp)
                        tmp=curr->left;
                }
                if(curr->right) {
                    curr->right->next = findLevelNext(curr->next);
                    if(!tmp)
                        tmp=curr->right;
                }
                curr=curr->next;
            }
            curr=tmp;
        }
        return root;
    }

    node* findLevelNext(node* root) {
        if(!root) return root;
        if(root->left) return root->left;
        if(root->right) return root->right;
        return findLevelNext(root->next);
    }
};

int main() {

    return 0;
}