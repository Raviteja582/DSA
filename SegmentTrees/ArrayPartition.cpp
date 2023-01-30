#include <bits/stdc++.h>
#include <cstring>
#include <vector>
using namespace std;

#define debarr(a, n)  cout << #a << " : "; for (int i = 0; i < n; i++) cerr << a[i] << " ";cerr << endl;
#define debmat(mat, row, col) cout << #mat << " :\n"; for (int i = 0; i < row; i++) { for (int j = 0; j < col; j++) cerr << mat[i][j] << " "; cerr << endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T> ostream &operator<<(ostream &os, const pair<S, T> &p) { return os << "(" << p.first << ", " << p.second << ")";}
template <class T> ostream &operator<<(ostream &os, const vector<T> &p) {os << "[ ";for (auto &it : p)os << it << " ";return os << "]"<<endl;}
template <class T> ostream &operator<<(ostream &os, const unordered_set<T> &p) {os << "[ ";for (auto &it : p)os << it << " ";return os << "]" <<endl;}
template <class S, class T> ostream &operator<<(ostream &os, const unordered_map<S, T> &p) {os << "[ ";for (auto &it : p)os << it << " ";return os << "]" << endl;}
template <class T> ostream &operator<<(ostream &os, const set<T> &p) {os << "[ ";for (auto &it : p)os << it << " ";return os << "]" << endl;}
template <class T> ostream &operator<<(ostream &os, const multiset<T> &p) {os << "[ ";for (auto &it : p)os << it << " ";return os << "]" << endl;}
template <class S, class T> ostream &operator<<(ostream &os, const map<S, T> &p) {os << "[ ";for (auto &it : p)os << it << " ";return os << "]" << endl;}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(',');cerr << str.substr(0, idx) << " : " << t << ",";dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "[";for (T i = a; i != b; ++i) {if (i != a)cerr << ", ";cerr << *i;}cerr << "]\n";}

class Solution {
public:
  bool partitionArray(int N, int K, int M, vector<int> &A) {
    bool dp[N + 1];
    memset(dp, false, sizeof(dp));
    dp[0] = 1;
    sort(A.begin(), A.end());
    for (int i = K; i <= N; i++) {
      int l = lower_bound(A.begin(), A.end(), A[i - 1] - M) - A.begin();
      int h = i - K;
      pr(i,l,h, A[i-1]-M);
      for (int j = l; j <= h; j++) {
        dp[i] |= dp[j];
        if (dp[i])
          break;
      }
      debarr(dp, N+1);
    }
    return dp[N];
  }
};

int main(){
  int n,m,k;
  cin>>n>>k>>m;
  vector<int> a(n,0);
  for(int i=0;i<n;i++) cin>>a[i];
  Solution sb;
  cout<<sb.partitionArray(n, k, m, a);
  return 0;
}