#include<bits/stdc++.h>
#include <cstdio>
#include <ostream>
#include <unordered_map>
#include <utility>
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
    int minThrow(int N, int arr[]){
        vector<vector<int>> dist(5, vector<int>(6, INT_MAX));
        unordered_map<int, int> m;
        for(int i=0;i<2*N;i+=2){
            arr[i]--,arr[i+1]--;
            if(arr[i]<arr[i+1]){
                pr("ladder",i,arr[i], arr[i+1]);
                m[arr[i]]=arr[i+1];
            } else {
                pr("snake",i, arr[i], arr[i+1]);
                m[arr[i]]=-arr[i+1];
            }
        }

        dist[0][0]=0;
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++){
                int num = ((i)*6+j);
                if(m.find(num)!=m.end()){
                    pr(num, m[num]);
                    if(m[num]>0){
                        int ladR=m[num]/6,ladC=m[num]%6;
                        dist[ladR][ladC]=min(dist[ladR][ladC],dist[i][j]);
                        pr(i,j, ladR, ladC);
                    } else {
                        continue;
                    }
                }
                pr(i,j,dist[i][j]);
                for(int k=1;k<=6;k++){
                    int dice=num+k;
                    if(dice>29)
                        break;
                    int row = dice/6;
                    int col = dice%6;
                    // if(i==0&&j==0){
                    //     if(dice<6)
                    //         dist[row][col]=1;
                    //     continue;
                    // }
                    dist[row][col]=min(
                                        dist[row][col],
                                        dist[i][j]+1
                                    );
                    pr(i,j,k,row,col,dist[row][col]);
                }
                debmat(dist, 5, 6);
            }
        }
        return dist[4][5];
    }
};

int main() {
    int n;
    freopen("stream_cerr.txt", "w", stderr);
    cin>>n;
    int arr[2*n];
    for(int i=0;i<(2*n);i++) cin>>arr[i];
    Solution sb;
    cout<<sb.minThrow(n, arr);
    return 0;
}