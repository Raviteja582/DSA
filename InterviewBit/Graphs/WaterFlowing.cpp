/*
    Link: https://www.interviewbit.com/problems/water-flow/
    Theory:
        The question clearly states that, from which cell of the grid the water
   can flow to both blue and red river. so we need to find those cells, such
   that if we pour water in it, it should go to both the rivers.

    Intution:
        The Cell which is common when we travel from Blue/Red river to all the
   cells which are greater than or equal to current cell, those are the cells
   which leads to both rivers.

    Application:
        DFS-1:
            From top left cells, we do a DFS where the next cell should be >=
   current cell and have the value 0 and mark the current cell to 1. DFS-2: From
   right bottom cells, we do a DFS where the next cell might be having 1 or 0
   and we mark the current to -1.
            - if cell having 1 means it already visited in DFS-1 and is a common
   cell, so add it to answer and marks as -1.
            - if cell having 0 means it visited first time, so mark it -1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
#define pp pair<int, int>

  int rv[4] = {0, 0, 1, -1};
  int cv[4] = {1, -1, 0, 0};
  int co = 0;

  bool isValid(pp node, int n, int m) {
    return node.first >= 0 && node.second >= 0 && node.first < n &&
           node.second < m;
  }

  void dfs(pp node, vector<vector<int>> &mat, vector<vector<int>> &vis,
           int flag) {
    if (vis[node.first][node.second] == 1)
      co += 1;
    vis[node.first][node.second] = flag;

    for (int i = 0; i < 4; i++) {
      pp neigh = {node.first + rv[i], node.second + cv[i]};
      if (isValid(neigh, mat.size(), mat[0].size()) &&
          vis[neigh.first][neigh.second] != flag &&
          mat[neigh.first][neigh.second] >= mat[node.first][node.second])
        dfs(neigh, mat, vis, flag);
    }
  }

  int solve(vector<vector<int>> &A) {
    co = 0;
    vector<vector<int>> vis(A.size(), vector<int>(A[0].size(), 0));

    for (int i = 0; i < A[0].size(); i++) {
      pp node = {0, i};
      if (vis[node.first][node.second] != 1)
        dfs({0, i}, A, vis, 1);
      node = {A.size() - 1, i};
      if (vis[node.first][node.second] != -1)
        dfs(node, A, vis, -1);
    }

    for (int i = 0; i < A.size(); i++) {
      pp node = {i, 0};
      if (vis[node.first][node.second] != 1)
        dfs(node, A, vis, 1);
      node = {i, A[0].size() - 1};
      if (vis[node.first][node.second] != -1)
        dfs(node, A, vis, -1);
    }

    return co;
  }
};

int main() { return 0; }