#include "../../tree.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  /*

      intution: for each node, we do recursive descending inorder for N-kth
     smallest element.
  */
  node *kth(node *root, int &k) {
    if (!root)
      return nullptr;
    node *right = kth(root->right, k);
    if (right)
      return right;
    k--;
    if (k == 0)
      return root;
    return kth(root->left, k);
  }
  int kthLargest(node *root, int K) { return kth(root, K)->val; }
};

int main() { return 0; }