/*
    Sort one Array based on another array.
*/

#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define F first
#define S second
#define EB emplace_back
#define MP make_pair
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define fr(i,n) for(lli i=0;i<(n); ++i)
#define rep(i,a,b) for(lli i=a;i<=b;++i)
#define per(i,a,b) for(lli i=a;i>=b; i--)
#define remin(a,b) (a=min((a), (b)))
#define remax(a,b) (a=max((a), (b)))
#define sz(x) (lli)(x).size()
#define endl '\n'

typedef long long int lli;          typedef long double ld;
typedef pair<lli,lli> ii;           typedef vector<lli> vi;
typedef vector<ii> vii;             typedef vector<vi> graph;
long long MOD = 1000000007;
long double EPS = 1e-9;

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
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(const string &str, T t, S... s) {int idx = str.find(',');cerr << str.substr(0, idx) << " : " << t << ",";dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "[";for (T i = a; i != b; ++i) {if (i != a)cerr << ", ";cerr << *i;}cerr << "]\n";}
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

lli partitionAlgo(lli arr1[], lli arr2[], lli low, lli high) {
  lli i = low, j = low, pivot = arr1[high];
  for (; j < high; j++) {
    if (arr1[j] < pivot) {
      swap(arr1[i], arr1[j]);
      swap(arr2[i], arr2[j]);
      i += 1;
    }
  }
  swap(arr1[i], arr1[high]);
  swap(arr2[i], arr2[high]);
  return i;
}

lli randomizedPartition(lli arr1[], lli arr2[], lli low, lli high) {
  lli r = low + ((lli)rand()) % (high - low);
  // log1("r: ",r,"\n");
  swap(arr1[r], arr1[high]);
  swap(arr2[r], arr2[high]);
  return partitionAlgo(arr1, arr2, low, high);
}

void quicksort(lli arr1[], lli arr2[], lli low, lli high) {
  if (low >= high)
    return;
  lli pivot = randomizedPartition(arr1, arr2, low, high);
  // log1("pivot: ", pivot, "\n");
  quicksort(arr1, arr2, low, pivot - 1);
  quicksort(arr1, arr2, pivot + 1, high);
}

int main() {
  lli n;
  cin >> n;
  lli arr1[n], arr2[n];
  rep(i, 0, n) cin >> arr1[i];
  rep(i, 0, n) cin >> arr2[i];
  quicksort(arr1, arr2, 0LL, n - 1);
  rep(i, 0, n) pr(arr1[i], " - ", arr2[i], "\n");
  return 0;
}