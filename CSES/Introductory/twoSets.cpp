#include<bits/stdc++.h>
#include <unordered_set>
#include <vector>
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

    lli n;
    cin>>n;

    lli sum = 0LL;
    if(n&1) {
        sum=((n+1LL)/2LL)*n;
    } else {
        sum = (n/2LL)*(n+1);
    }
    if(sum&1) cout<<"NO";
    else {

        lli tmp = n;
        cout<<"YES"<<endl;
        unordered_set<int> ss;
        sum/=2LL;
        // pr(sum);
        while(sum>n) {
            ss.insert(n);
            sum-=n;
            n-=1;
        }
        if(sum!=0) ss.insert(sum);

        cout<<ss.size()<<endl;
        for(auto x: ss) {
            cout<<x<<" ";
        }
        cout<<endl;
        cout<<(tmp-ss.size())<<endl;
        for(int i=1;i<=n;i++) {
            if(ss.find(i)!=ss.end()) continue;
            cout<<i<<" ";
        }
    }
    return 0;
}


/**
    Idea:
        if sum of 'n' numbers is even, then we can split, else 'NO'
        to split, just subtract, n, n-1, n-2,.... untile (sum/2) is zero or (sum/2)<=(n-x)
        then remaining elements are second set.
*/