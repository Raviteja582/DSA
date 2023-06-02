#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
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
    int findCount(const vector<vector<int>> &A,int val){
        int n=A.size(), m=A[0].size();
        int count = 0;
        for(int i=0;i<n;i++){
            int indx = upper_bound(A[i].begin(), A[i].end(), val) - A[i].begin();
            count+=(indx);
        }
        return count;
    }
    int findMedian(vector<vector<int> > &A){
        int low=INT_MAX, high=INT_MIN, mid, ans;
        int n=A.size(), m=A[0].size();
        if(n*m==1)
            return A[0][0];

        int req_count = ((n*m)/2)+1;

        for(int i=0;i<n;i++)
            low = min(low, A[i][0]);
        for(int i=0;i<n;i++)
            high = max(high, A[i][m-1]);

        while(low<=high){
            mid=(low+high)/2;
            int count = findCount(A, mid);
            if(count<req_count){
                ans=mid+1;
                low=mid+1;
            } else {
                high=mid-1;
            }
        }

        return ans;
    }
};

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n, vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    // debmat(v, n, m);
    Solution sb;
    cout<<sb.findMedian(v);
    return 0;
}