#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct num {
  vector<int> vv;
  int index;
  num(){};
  num(vector<int> &x, int val) {
    vv = x;
    index = val;
  }
};

struct node {
  node *ch[2];
  int val;
  node() {
    ch[0] = nullptr, ch[1] = nullptr;
    val = -1;
  }
};

class Solution {
public:
  static bool comp(const num *a, const num *b) {
    vector<int> v1 = a->vv;
    vector<int> v2 = b->vv;

    if (v1[1] != v2[1])
      return v1[1] < v2[1];
    return a->index < b->index;
  }

  void insert(node *root, int num) {
    node *curr = root;
    for (int i = 31; i >= 0; i--) {
      int bit = (num >> i) & 1;
      if (curr->ch[bit] == nullptr)
        curr->ch[bit] = new node;
      curr = curr->ch[bit];
    }
    curr->val = num;
  }

  int search(node *root, int num) {
    node *curr = root;
    for (int i = 31; i >= 0; i--) {
      int bit = (num >> i) & 1;
      if (curr->ch[1 - bit] != nullptr)
        curr = curr->ch[1 - bit];
      else if (curr->ch[bit] == nullptr)
        return -1;
      else
        curr = curr->ch[bit];
    }
    return (curr->val) ^ num;
  }

  vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries) {
    // take queries as offline
    node *root = new node;
    sort(nums.begin(), nums.end());
    vector<int> ans(queries.size(), 0);
    vector<num *> inp(queries.size());
    for (int i = 0; i < queries.size(); i++) {
      inp[i] = new num(queries[i], i);
    }
    sort(inp.begin(), inp.end(), comp);

    int j = 0;
    for (int i = 0; i < queries.size(); i++) {
      for (; j < nums.size(); j++) {
        if (nums[j] > inp[i]->vv[1])
          break;
        if (nums[j] <= inp[i]->vv[1]) {
          insert(root, nums[j]);
        }
      }
      ans[inp[i]->index] = search(root, inp[i]->vv[0]);
    }

    return ans;
  }
};

int main() { return 0; }