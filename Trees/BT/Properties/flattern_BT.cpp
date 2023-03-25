#include "../../tree.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  node *prev = nullptr;

  void flatter_recursive(node *root) {
    if (!root)
      return;
    flatter_recursive(root->right);
    flatter_recursive(root->left);
    root->right = prev;
    root->left = nullptr;
    prev = root;
  }

  void flattern_iterative(node *root) {
    if (!root)
      return;
    stack<node *> st;
    st.push(root);
    while (!st.empty()) {
      node *tmp = st.top();
      st.pop();
      if (tmp->right)
        st.push(tmp->right);
      if (tmp->left)
        st.push(tmp->left);
      if (st.empty())
        break;
      tmp->right = st.top();
      tmp->left = nullptr;
    }
  }

  void flatter_morrison(node *root) {
    if (!root)
      return;

    node *curr = root;
    while (!curr) {
      node *prev = curr->left;

      if(prev) {
        while (prev->right) {
            prev = prev->right;
        }
        prev->right = curr->right;
        curr->right = prev;
        curr->left = nullptr;
        curr = curr->right;
      }
      else {
        curr=curr->right;
      }
    }
  }
};

int main() { return 0; }