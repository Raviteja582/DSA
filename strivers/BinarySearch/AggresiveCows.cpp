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
    bool check(vector<int> &arr, int mid, int cows) {
        int init=1, n=arr.size();
        int start=0, curr=0;
        for(int i=1;i<n;i++) {
            curr = arr[i]-arr[start];
            if(curr>=mid){
                init++;
                start=i;
            }
        }
        return init>=cows;
    }
    int findMaxDistance(vector<int> &arr, int cows) {
        int ans = 0, n = arr.size();
        sort(arr.begin(), arr.end());
        int mini=arr[0], maxi=arr[n-1]-arr[0];
        int low = 0, high = maxi-mini;
        while(low<=high) {
            int mid = (low+high)/2;
            if(check(arr, mid, cows)){
                low=mid+1;
            } else{
                high = mid-1;
            }
        }
        return high;
    }
};

int main() {
    int t;cin>>t;
    while(t--) {
        int n, c;
        cin>>n>>c;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution sb;
        cout<<sb.findMaxDistance(arr, c)<<"\n";
    }
    return 0;
}