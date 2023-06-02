#include <bits/stdc++.h>
#include <cstddef>
#include <vector>
using namespace std;

struct node {
  node *ch[2];
  bool row;
  node() {
    ch[0] = nullptr;
    ch[1] = nullptr;
    row = false;
  }
};

class Solution {
public:
  bool insert(node *root, vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
      int bit = v[i];
      if (root->ch[bit] == nullptr)
        root->ch[bit] = new node;
      root = root->ch[bit];
    }
    if (!root->row) {
      root->row = true;
      return false;
    } else {
      return true;
    }
  }

  vector<int> repeatedRows(vector<vector<int>> matrix, int M, int N) {
    node *root = new node;

    vector<int> ans;
    for (int i = 0; i < M; i++) {
      bool isExist = insert(root, matrix[i]);
      if (isExist)
        ans.push_back(i);
    }

    return ans;
  }
};

int main() { return 0; }