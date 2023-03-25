#include "../../tree.h"
#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> usingTwoStacks(node *root) {
    stack<node *> s1;
    stack<int> s2;
    if (!root) {
      return vector<int>();
    }
    vector<int> ans;
    s1.push(root);
    while (!s1.empty()) {
      node *tmp = s1.top();
      s1.pop();
      s2.push(tmp->val);
      if (tmp->left)
        s1.push(tmp->left);
      if (tmp->right)
        s1.push(tmp->right);
    }
    while (!s2.empty()) {
      ans.push_back(s2.top());
      s2.pop();
    }
    return ans;
  }

  vector<int> using_OneStack(node *root) {
    if (!root) {
      return vector<int>();
    }

    stack<node *> st;
    vector<int> ans;
    node *curr = root;
    while (true) {
      if (curr) {
        st.push(curr);
        curr = curr->left;
      } else {
        if (st.empty())
          break;
        node *tmp = st.top()->right;
        if (tmp) {
          curr = tmp;
        } else {
          tmp = st.top();
          st.pop();
          ans.push_back(tmp->val);
          while (!st.empty() && st.top()->right == tmp) {
            tmp = st.top();
            st.pop();
            ans.push_back(tmp->val);
          }
        }
      }
    }
    return ans;
  }
};

int main() { return 0; }