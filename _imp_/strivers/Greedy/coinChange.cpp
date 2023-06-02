#include<bits/stdc++.h>
#include <climits>
#include <cstring>
using namespace std;
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
class Solution {
    public:
    int minCoins(int coins[], int M, int V){
        int dp[2][V+1];
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<=V;i++){
            if(i==0)
                dp[0][i]=0;
            else if(i%coins[0]==0)
                dp[0][i]=i/coins[0];
            else
                dp[0][i]=-1;
        }

        int ci=1;
        for(int i=1;i<M;i++){
            for(int j=0;j<=V;j++) {
                if(j==0)
                    dp[ci][j]=0;
                else if(j<coins[i])
                    dp[ci][j]= (dp[1-ci][j]==-1) ? -1 : dp[1-ci][j];
                else {
                    int minCoins;
                    if(dp[1-ci][j]==-1)
                        minCoins=INT_MAX;
                    else
                        minCoins=dp[1-ci][j];
                    
                    if(dp[ci][j-coins[i]]!=-1 && minCoins!=INT_MAX)
                        dp[ci][j]=min(1+dp[ci][j-coins[i]], minCoins);
                    else if(dp[ci][j-coins[i]]==-1)
                        dp[ci][j]= (minCoins==INT_MAX) ? -1 : minCoins ;
                    else
                        dp[ci][j]=1+dp[ci][j-coins[i]];
                }
            }
            pr(coins[i]);
            debarr(dp[ci], V+1);
            ci=1-ci;
        }
        return dp[1-ci][V];
    } 
};

int main() {
    int V,M;
    cin>>V>>M;
    int arr[M];
    for(int i=0;i<M;i++)
        cin>>arr[i];
    Solution sb;
    cout<<sb.minCoins(arr, M, V);
    return 0;
}