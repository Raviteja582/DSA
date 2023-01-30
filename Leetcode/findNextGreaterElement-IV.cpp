//link: https://leetcode.com/problems/next-greater-element-iv/
#include<bits/stdc++.h>
#include <iterator>
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
template <class T> void dbs(const string &str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(',');cerr << str.substr(0, idx) << " : " << t << ",";dbs(str.substr(idx + 1), s...);}
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
vector<vector<int>> greaterElement(vector<int>& nums, const vector<vector<int>> &prev) {
    vector<int> ms;
    vector<vector<int>> pprev(nums.size());
    cout<<"Initial prev: ->\n";
    // for(int k=0;k<(int)prev.size();k++){
    //     if(prev[k].size()){
    //         cout<<k<<" -> ";
    //         for(int l=0;l<(int)prev[k].size();l++)
    //             cout<<prev[k][l]<<" ";
    //         cout<<'\n';
    //     }
    // }
    for (int i = nums.size() - 1; i >= 0; --i) {
        for (int j : prev.empty() ? vector<int>{i} : prev[i]) {
            auto it = upper_bound(ms.rbegin(), ms.rend(), j, [&](int i, int j){ return nums[i] < nums[j]; });
            if (it != ms.rend()){
                pprev[*it].push_back(j);
                pr(j, *it);
            }
        }
        // for(int k=0;k<(int)nums.size();k++){
        //     if(pprev[k].size()){
        //         cout<<k<<" -> ";
        //         for(int l=0;l<(int)pprev[k].size();l++)
        //             cout<<pprev[k][l]<<" ";
        //         cout<<'\n';
        //     }
        // }
        while(!ms.empty() && nums[ms.back()] < nums[i])
            ms.pop_back();
        ms.push_back(i);
        debarr(ms, (int)ms.size());
    }
    return pprev;
}
vector<int> secondGreaterElement(vector<int>& nums, int k = 2) {
    vector<int> res(nums.size(), -1);
    vector<vector<int>> prev;
    while (--k >= 0)
        prev = greaterElement(nums, prev);
    for (int i = nums.size() - 1; i >= 0; --i)
     
        for (int j : prev[i])
            res[j] = nums[i];
    return res;
}

int main() {
    vector<int> v({2,4,0,9,6});
    vector<int> ans = secondGreaterElement(v);
    debarr(ans, 5);
    return 0;
}