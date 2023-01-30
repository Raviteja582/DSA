// Link:
// https://practice.geeksforgeeks.org/problems/minimum-steps-to-delete-a-string2956/1?page=1&status[]=unsolved&curated[]=4&sortBy=submissions

#include <bits/stdc++.h>
#include <cstring>
#include <vector>
using namespace std;

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

class Solution {
	public:
    int equalPartition(int N, int arr[]){
      int sum=0;
      fr(i, N) sum+=arr[i];
      v.resize(sum+1);
      rep(i, 0, sum) v[i]=vector<int>(sum+1,0);
      return dp(arr[0],0, 0, arr, N);
    }
};

int main() {
  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    int n;
    cin>>n;
    int arr[n];
    fr(i,n) cin>>arr[i];
    Solution ob;
    cout << ob.equalPartition(n, arr)<< "\n";
  }
  return 0;
}