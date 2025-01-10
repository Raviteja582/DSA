#include <bits/stdc++.h>
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
  for (const auto &it : p)
    os << it << " ";
  return os << "]" << endl;
}
template <class T> ostream &operator<<(ostream &os, const unordered_set<T> &p) {
  os << "[ ";
  for (const auto &it : p)
    os << it << " ";
  return os << "]" << endl;
}
template <class S, class T>
ostream &operator<<(ostream &os, const unordered_map<S, T> &p) {
  os << "[ ";
  for (const auto &it : p)
    os << it << " ";
  return os << "]" << endl;
}
template <class T> ostream &operator<<(ostream &os, const set<T> &p) {
  os << "[ ";
  for (const auto &it : p)
    os << it << " ";
  return os << "]" << endl;
}
template <class T> ostream &operator<<(ostream &os, const multiset<T> &p) {
  os << "[ ";
  for (const auto &it : p)
    os << it << " ";
  return os << "]" << endl;
}
template <class S, class T>
ostream &operator<<(ostream &os, const map<S, T> &p) {
  os << "[ ";
  for (const auto &it : p)
    os << it << " ";
  return os << "]" << endl;
}
template <class T> void dbs(string str, T t) {
  cerr << str << " : " << t << "\n";
}
template <class T, class... S> void dbs(const string &str, T t, S... s) {
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

void convertToArray(string &input) {
  std::replace(input.begin(), input.end(), '[', '{');
  std::replace(input.begin(), input.end(), ']', '}');
}

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    bool fc = false, fr = false;
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < n; i++) {
      if (matrix[0][i] == 0) {
        fr = true;
        break;
      }
    }

    for (int i = 0; i < m; i++) {
      if (matrix[i][0] == 0) {
        fc = true;
        break;
      }
    }

    for (int i = m - 1; i > 0; i--) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
          break;
        }
      }
    }

    pr(fc, fr);
    debmat(matrix, m, n);

    for (int i = 1; i < m; i++) {
      if (matrix[i][0] == 0)
        for (int j = 0; j < n; j++)
          matrix[i][j] = 0;
    }

    for (int i = 0; i < n; i++) {
      if (matrix[0][i] == 0)
        for (int j = 0; j < m; j++)
          matrix[j][i] = 0;
    }

    if (fr)
      for (int i = 0; i < n; i++)
        matrix[0][i] = 0;
    if (fc)
      for (int i = 0; i < m; i++)
        matrix[i][0] = 0;
  }
};

int main() {
  vector<vector<int>> v = {
    {3, 5, 5, 6, 9, 1, 4, 5, 0, 5},
    {2, 7, 9, 5, 9, 5, 4, 9, 6, 8},
    {6, 0, 7, 8, 1, 0, 1, 6, 8, 1},
    {7, 2, 6, 5, 8, 5, 6, 5, 0, 6},
    {2, 3, 3, 1, 0, 4, 6, 5, 3, 5},
    {5, 9, 7, 3, 8, 8, 5, 1, 4, 3},
    {2, 4, 7, 9, 9, 8, 4, 7, 3, 7},
    {3, 5, 2, 8, 8, 2, 2, 4, 9, 8}
  };
  Solution sb;
  string inp = "[[3,5,5,6,9,1,4,5,0,5],[2,7,9,5,9,5,4,9,6,8],[6,0,7,8,1,0,1,6,"
               "8,1],[7,2,6,5,8,5,6,5,0,6],[2,3,3,1,0,4,6,5,3,5],[5,9,7,3,8,8,"
               "5,1,4,3],[2,4,7,9,9,8,4,7,3,7],[3,5,2,8,8,2,2,4,9,8]]";
  // convertToArray(inp);
  pr(inp);
  sb.setZeroes(v);
  debmat(v, v.size(), v[0].size());
  return 0;
}