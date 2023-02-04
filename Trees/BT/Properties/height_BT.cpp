#include "../../tree.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

  // iterative approach
  int maxDepth(node *root) {
    int result = 0, current_depth = 0;
    node *current = root, *stack = nullptr;

    while (current || stack) {
      if (current) {
        current->val = current_depth;
        node *const next = current->left;
        current->left = stack;
        stack = current;
        current = next;
        ++current_depth;
      } else {
        result = max(result, current_depth);
        current = stack->right;
        current_depth = stack->val + 1;
        stack = stack->left;
      }
    }

    return result;
  }
};

int main() { return 0; }