#include "../../tree.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
#define pp pair<pair<int, int>, int>

  pp postOrder(node *root, int &maxSum) {
    if (root == nullptr)
      return {{INT_MAX, INT_MIN}, 0};

    pp left = postOrder(root->left, maxSum);
    pp right = postOrder(root->right, maxSum);

    // condition that current node is root of child trees in BST
    if (left.first.second < root->val && right.first.first > root->val) {
      int currSum = left.second + right.second + root->val;
      maxSum = max(maxSum, currSum);
      return {{min(left.first.first, root->val),
               max(right.first.second, root->val)},
              currSum};
    }

    // current node is not a BST, so return invalid ranges to parent...
    else {
      return {{INT_MIN, INT_MAX}, max(left.second, right.second)};
    }
  }

  int maxSumBST(node *root) {
    int ans = 0;
    postOrder(root, ans);
    return ans;
  }
};

int main() { return 0; }