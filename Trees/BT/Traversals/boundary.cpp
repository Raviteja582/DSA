#include "../../tree.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // should add from top to bottom, no child nodes
  void leftBoundary(node *root, vector<int> &ans) {
    if (!root)
      return;
    if (!root->left && !root->right)
      return;
    ans.push_back(root->val);
    if (root->left)
      leftBoundary(root->left, ans);
    else
      leftBoundary(root->right, ans);
  }

  // should add from bottom to top, no child nodes
  void rightBoundary(node *root, vector<int> &ans) {
    if (!root)
      return;
    if (!root->left && !root->right)
      return;
    if (root->right) {
      rightBoundary(root->right, ans);
    } else {
      rightBoundary(root->left, ans);
    }
    ans.push_back(root->val);
  }

  // should only add leaf nodes, except root.
  void inorder(node *root, vector<int> &ans) {
    if (!root)
      return;
    stack<node*> st;
    node *curr = root;
    while (true) {
      if (curr) {
        st.push(curr);
        curr = curr->left;
      } else {
        if (st.empty())
          break;
        node *tmp = st.top();
        st.pop();
        if (tmp->right)
          curr = tmp->right;
        else if (!tmp->left && tmp != root)
          ans.push_back(tmp->val);
      }
    }
  }

  vector<int> traverseBoundary(node *root) {
    vector<int> ans;
    if (!root)
      return ans;
    ans.push_back(root->val);
    leftBoundary(root->left, ans);
    inorder(root, ans);
    rightBoundary(root->right, ans);
    return ans;
  }
};

int main() { return 0; }