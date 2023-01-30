#include <algorithm>
#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

#define debarr(a, n)  cout << #a << " : "; for (int i = 0; i < n; i++) cerr << a[i] << " ";cerr << endl;
#define debmat(mat, row, col) cout << #mat << " :\n"; for (int i = 0; i < row; i++) { for (int j = 0; j < col; j++) cerr << mat[i][j] << " "; cerr << endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T> ostream &operator<<(ostream &os, const pair<S, T> &p) { return os << "(" << p.first << ", " << p.second << ")";}
template <class T> ostream &operator<<(ostream &os, const vector<T> &p) {os << "[ ";for (const auto &it : p)os << it << " ";return os << "]"<<endl;}
template <class T> ostream &operator<<(ostream &os, const unordered_set<T> &p) {os << "[ ";for (const auto &it : p)os << it << " ";return os << "]" <<endl;}
template <class S, class T> ostream &operator<<(ostream &os, const unordered_map<S, T> &p) {os << "[ ";for (const auto &it : p)os << it << " ";return os << "]" << endl;}
template <class T> ostream &operator<<(ostream &os, const set<T> &p) {os << "[ ";for (const auto &it : p)os << it << " ";return os << "]" << endl;}
template <class T> ostream &operator<<(ostream &os, const multiset<T> &p) {os << "[ ";for (const auto &it : p)os << it << " ";return os << "]" << endl;}
template <class S, class T> ostream &operator<<(ostream &os, const map<S, T> &p) {os << "[ ";for (const auto &it : p)os << it << " ";return os << "]" << endl;}
template <class T> void dbs(const string &str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(',');cerr << str.substr(0, idx) << " : " << t << ",";dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "[";for (T i = a; i != b; ++i) {if (i != a)cerr << ", ";cerr << *i;}cerr << "]\n";}

class Solution {
    public:
    int rv[4]={-1, 0, 1, 0};
    int cv[4]={0, -1, 0, 1};

    bool isValid(int nr, int nc, int n, int m) {
        return nr>=0 && nc>=0 && nr<n && nc<m;
    }
    int orangesRotting(vector<vector<int>>& grid) {
      int n=grid.size(), m=grid[0].size();
      vector<vector<int>> dp(n, vector<int>(m, -1)); // store time
      
      queue<pair<int,int>> st;
      for(int i=0;i<n;i++) {
          for(int j=0;j<m;j++) {
              if(grid[i][j]==1)
                  dp[i][j]=0;
              else if(grid[i][j]==2) {
                  dp[i][j]=0;
                  st.push(make_pair(i,j));
              }
          }
      }
      
      int ans=0;
      while(!st.empty()) {
          pair<int,int> curr=st.front();st.pop();
          pr(curr);
          for(int i=0;i<4;i++) {
              int nr=curr.first+rv[i], nc=curr.second+cv[i];
              if(
                  isValid(nr, nc, n, m) &&
                  grid[nr][nc]==1
              ) {
                  pr(make_pair(nr, nc));
                  grid[nr][nc]=2;
                  dp[nr][nc]=dp[curr.first][curr.second]+1;
                  ans=max(ans, dp[nr][nc]);
                  st.push({nr,nc});
              }
          }
      }
      debmat(grid, n, m);

      debmat(dp, n, m);
      return ans;
    }
};

int main() {

  vector<vector<int>> grid = {
    {0, 1, 2},
    {0, 1, 2}, 
    {2, 1, 1}
  };

  Solution sb;
  int ans = sb.orangesRotting(grid);
  pr(ans);
  return 0;
}