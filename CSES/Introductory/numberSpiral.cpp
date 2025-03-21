#include<bits/stdc++.h>
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


void convertToArray(string &input) { replace(input.begin(), input.end(), '[', '{'); replace(input.begin(), input.end(), ']', '}');}
int main() {
  FAST;
  int t;
  cin>>t;
  while(t--) {
    lli r,c;
    cin>>r>>c;
    if(r<=c) {
      if(c&1) 
        cout<<c*c+1-r<<endl;
      else cout<<(c-1)*(c-1) + r<<endl;
    } else {
      if(r&1) cout<<(r-1)*(r-1)+c<<endl;
      else cout<< r*r+1-c<<endl;
    }
  }
  return 0;
}

/**
  IDEA:
        1 2 3 4  5  6
      1 1 2 9 10 25 26
      2 4 3 8 11 24 27 
      3 5 6 7 12 23 28
      4 16 15 14 13 22 29
      5 17 18 19 20 21 30

      Observation:
        row: (r>=c)
          every even index start from index^2 and in reverse order sequence of length index
            starting = index^2
            required number in sequence = (c-1) including starting...
            final number = starting - required number
                         = index^2 - (c-1) 
          every odd index start from (index-1)^2+1 and in sequence of length index
            starting = (index-1)^2+1
            required number in sequence = (c+1) including starting...
            final number = starting + required number
                         = (index-1)^2 + 1 + (c-1)
                         = (index-1)^2 + c
        column:
          every odd index start from index^2 and in reverse order sequence of length index
            starting = index^2
            required number in sequence = (r-1) including starting...
            final number = starting - required number
                         = index^2 - (r-1)
          every even index start from (index-1)^2+1 and in sequence of length index.
            starting = (index-1)^2+1
            required number in sequence = (r-1) including starting...
            final number = starting + required number
                         = (index-1)^2 + 1 + (r-1)
                         = (index-1)^2+r
*/