#include<bits/stdc++.h>
#include <climits>
#include <cstdint>
#include <stack>
#include <unordered_map>
#include <utility>
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

unordered_map<char, pair<int,int>> m={
    { '^', { 4, 1 } },
    { '/', { 3, 0 } },
    { '*', { 3, 0 } },
    { '-', { 2, 0 } },
    { '+', { 2, 0 } }
};

bool isOperator(char c){
    return m.find(c)==m.end();
}

pair<int, int> getRules(char c){
    if(isOperator(c)){
        return m[c];
    } 
    return {-1, -1};
}

int getPrecendency(char c){
    pair<int, int> p = getRules(c);
    if(p.first != -1)
        return p.first;
    return INT_MAX;
}

int getAssociativity(char c){
    pair<int, int> p = getRules(c);
    if(p.first!=-1)
        return p.second;
    return INT_MAX;
}

string InfixToPostfix(const string &s){
    string ans="";
    stack<int> ops, opt;
    for(char c: s){
        if(isOperator(c)){
            /*
                if associativity = 0, then pop operators >= current operator
                if associativity = 1, then pop operators > current operator
            */
            int precedency = getPrecendency(c);
            int associativity = getAssociativity(c);
            if(precedency == INT_MAX){
                return "UNKNOWN";
            }
            while( !ops.empty() &&
                ( (associativity==0 && (precedency <= getPrecendency(ops.top()))) || 
                  (associativity==1 && (precedency < getPrecendency(ops.top())))
                ) 
            ) {
                char ot = ops.top();
                opt.push(ot);
                ops.pop();
            }
            ops.push(c);
        } else if(c=='('){
            ops.push('(');
        } else if(c==')'){
            while(!ops.empty() && ops.top() != '('){
                char op = ops.top();
                opt.push(op);
                ops.pop();
            }
            if(!ops.empty())
                ops.pop();
        } else {
            opt.push(c);
        }
    }

    while(!ops.empty()){
        char op = ops.top();
        if(op == '(' || op == ')')
            return "UNKNOWN";
        else
            opt.push(op);
        ops.pop();
    }
    while(!opt.empty()){
        ans.push_back(opt.top());
        opt.pop();
    }
    return ans;
}

int main() {
    FAST;
    lli t;
    cin>>t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin, s);
        cout<<InfixToPostfix(s)<<"\n";
    }
    return 0;
}