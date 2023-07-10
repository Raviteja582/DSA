#include <bits/stdc++.h>
#include <cstring>
#include <vector>
using namespace std;

#define FAST                                                                   \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define F first
#define S second
#define EB emplace_back
#define MP make_pair
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define fr(i, n) for (lli i = 0; i < (n); ++i)
#define rep(i, a, b) for (lli i = a; i <= b; ++i)
#define per(i, a, b) for (lli i = a; i >= b; i--)
#define remin(a, b) (a = min((a), (b)))
#define remax(a, b) (a = max((a), (b)))
#define sz(x) (lli)(x).size()
#define endl '\n'

typedef long long int lli;
typedef long double ld;
typedef pair<lli, lli> ii;
typedef vector<lli> vi;
typedef vector<ii> vii;
typedef vector<vi> graph;
long long MOD = 1000000007;
long double EPS = 1e-9;

#define debarr(a, n)                                                           \
  cout << #a << " : ";                                                         \
  for (int i = 0; i < n; i++)                                                  \
    cerr << a[i] << " ";                                                       \
  cerr << endl;
#define debmat(mat, row, col)                                                  \
  cout << #mat << " :\n";                                                      \
  for (int i = 0; i < row; i++) {                                              \
    for (int j = 0; j < col; j++)                                              \
      cerr << mat[i][j] << " ";                                                \
    cerr << endl;                                                              \
  }
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)

template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T> ostream &operator<<(ostream &os, const vector<T> &p) {
  os << "[ ";
  for (auto &it : p)
    os << it << " ";
  return os << "]" << endl;
}
template <class T> ostream &operator<<(ostream &os, const unordered_set<T> &p) {
  os << "[ ";
  for (auto &it : p)
    os << it << " ";
  return os << "]" << endl;
}
template <class S, class T>
ostream &operator<<(ostream &os, const unordered_map<S, T> &p) {
  os << "[ ";
  for (auto &it : p)
    os << it << " ";
  return os << "]" << endl;
}
template <class T> ostream &operator<<(ostream &os, const set<T> &p) {
  os << "[ ";
  for (auto &it : p)
    os << it << " ";
  return os << "]" << endl;
}
template <class T> ostream &operator<<(ostream &os, const multiset<T> &p) {
  os << "[ ";
  for (auto &it : p)
    os << it << " ";
  return os << "]" << endl;
}
template <class S, class T>
ostream &operator<<(ostream &os, const map<S, T> &p) {
  os << "[ ";
  for (auto &it : p)
    os << it << " ";
  return os << "]" << endl;
}
template <class T> void dbs(string str, T t) {
  cerr << str << " : " << t << "\n";
}
template <class T, class... S> void dbs(string str, T t, S... s) {
  int idx = str.find(',');
  cerr << str.substr(0, idx) << " : " << t << ",";
  dbs(str.substr(idx + 1), s...);
}
template <class T> void prc(T a, T b) {
  cerr << "[";
  for (T i = a; i != b; ++i) {
    if (i != a)
      cerr << ", ";
    cerr << *i;
  }
  cerr << "]\n";
}
lli binpow(lli b, lli p, lli mod) {
  lli ans = 1;
  b %= mod;
  for (; p; p >>= 1) {
    if (p & 1)
      ans = ans * b % mod;
    b = b * b % mod;
  }
  return ans;
}

/*
 Strivers DP on stocks - 2
*/
class StocksDP_Unlimited {
  /**
      1. Unlimited stocks
      2. Buy only after completing a sell or buy a new one
      3. return maximum profit.
  */

  /*
      T.C = O(N)
      S.C = Constant space.
      0 -> sell
      1 -> buy
  */
  int maxProfit_tabulation(int n, const int arr[]) {
    int dp[2][2];
    memset(dp, 0, sizeof(dp));

    int ci = 1;
    for (int i = n - 1; i >= 0; i--) {
      dp[ci][0] = max(arr[i] + dp[1 - ci][1], dp[1 - ci][0]); // sell
      dp[ci][1] = max(dp[1 - ci][0] - arr[i], dp[1 - ci][1]); // buy
      ci = 1 - ci;
    }
    return dp[1 - ci][1];
  }

  /*
      T.C = O(2^n)
      S.C = O(2^n) recursion stack space.
  */
  int maxProfit_recursion_without_memorization(int ind, bool buy, int arr[],
                                               int n) {
    if (ind == n)
      return 0;

    if (buy)
      return max(
          maxProfit_recursion_without_memorization(ind + 1, false, arr, n) -
              arr[ind],
          maxProfit_recursion_without_memorization(ind + 1, true, arr, n));
    // sell
    return max(
        maxProfit_recursion_without_memorization(ind + 1, true, arr, n) +
            arr[ind],
        maxProfit_recursion_without_memorization(ind + 1, false, arr, n));
  }

  /*
      -> vector initiation = vector<vector<int>> v(n, vector<int>(2,0))
      T.C = O(N)
      S.C = O(N) recursion stack space.
  */
  int maxProfit_recursion_with_memorization(int ind, bool buy, int n, int arr[],
                                            vector<vector<int>> &v) {

    if (ind == n)
      return 0;

    if (v[ind][buy] != -1)
      return v[ind][buy];

    if (buy)
      v[ind][buy] =
          max(maxProfit_recursion_with_memorization(ind + 1, false, n, arr, v) -
                  arr[ind],
              maxProfit_recursion_with_memorization(ind + 1, true, n, arr, v));
    else
      v[ind][buy] =
          max(maxProfit_recursion_with_memorization(ind + 1, true, n, arr, v) +
                  arr[ind],
              maxProfit_recursion_with_memorization(ind + 1, false, n, arr, v));

    return v[ind][buy];
  }

  int greedy_way(int n, int arr[]) {

    int currStock = arr[0];
    int profit = 0;
    for (int i = 1; i < n; i++) {
      if (currStock > arr[i])
        currStock = arr[i];
      else {
        profit += arr[i] - currStock;
        currStock = INT_MAX; // don't buy current stock.
      }
    }
    return profit;
  }
};