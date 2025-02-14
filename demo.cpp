#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstddef>
#include <cstring>
#include <functional>
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

bool cmp(pair<int, int> &a, pair<int, int> &b) { return a.first < b.first; }

int check_log_history(const vector<string> &events) {
  stack<int> acquire_stack;
  unordered_set<int> acquired_locks;

  for (size_t i = 0; i < events.size(); ++i) {
    istringstream ss(events[i]);
    string action;
    int lock_id;
    ss >> action >> lock_id; // Parse action and lock ID

    if (action == "ACQUIRE") {
      // Rule: Lock should not be acquired twice
      if (acquired_locks.count(lock_id)) {
        return i + 1;
      }
      acquire_stack.push(lock_id);
      acquired_locks.insert(lock_id);
    } else if (action == "RELEASE") {
      // Rule: Lock should not be released if never acquired
      if (acquired_locks.count(lock_id) == 0) {
        return i + 1;
      }
      // Rule: Locks should be released in LIFO order
      if (acquire_stack.top() != lock_id) {
        return i + 1;
      }
      acquire_stack.pop();
      acquired_locks.erase(lock_id);
    }
  }

  // If the stack is not empty, it means there are dangling acquired locks
  return acquire_stack.empty() ? 0 : events.size() + 1;
}

int checkPalindrome(const string &s) {
  vector<vector<bool>> isPali(s.size(), vector<bool>(s.size(), false));
  int count=0;
  for (int i = 0; i < s.size(); i++) {
    int x = 0, y = i;
    while (x < s.size() && y < s.size()) {
      if (s[x] == s[y] && (x == y || y == x + 1 || isPali[x + 1][y - 1])) {
        isPali[x][y] = true;
        count++;
      }
      x++;
      y++;
    }
  }

  return count;
}

int main() {
  vector<string> v = {"ACQUIRE 123", "ACQUIRE 364", "ACQUIRE 84",
                      "RELEASE 84",  "RELEASE 364", "ACQUIRE 456"};
  cout << checkPalindrome("wowpurerocks");
  return 0;
}