#include<bits/stdc++.h>
#include <queue>
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
    #define pp pair<int,int>
    vector<vector<int>> dist;
    int n;
    int kv[2][2]={{-1,1},{-2,2}};

    bool isValid(pp node){
        return node.first>=0 && node.first<n && node.second>=0 && node.second<n;
    }

    void bfs(int tarR, int tarC){
        dist[tarR][tarC]=0;
        pp node=make_pair(tarR, tarC);
        queue<pp> q;
        q.push(node);
        while(!q.empty()){
            pp curr=q.front();q.pop();
            int ci=1;
            while(true){
                for(int i=0;i<2;i++){
                    for(int j=0;j<2;j++){
                        int nxtR = curr.first + kv[1-ci][i];
                        int nxtC = curr.second + kv[ci][j];
                        pp nxtNode = make_pair(nxtR, nxtC);
                        if(
                            isValid(nxtNode) &&
                            (dist[nxtR][nxtC] > dist[curr.first][curr.second]+1)
                        ){
                            dist[nxtR][nxtC]=dist[curr.first][curr.second]+1;
                            q.push(nxtNode);
                        }
                    }
                }
                ci=1-ci;
                if(ci==1)
                    break;
            }
        }
    }
    
    int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    n=N;
        dist.assign(N, vector<int>(N,INT_MAX));
        int tarR=--TargetPos[0], tarC=--TargetPos[1];
        pp node = make_pair(tarR, tarC);
        bfs(tarR, tarC);
        return dist[--KnightPos[0]][--KnightPos[1]];
	}
};

int main() {
    int n;
    cin>>n; // board size

    // 1-based index
    vector<int> KnightPos(2);
    cin>>KnightPos[0]>>KnightPos[1];

    // 1-based index
    vector<int> TargetPos(2);
    cin>>TargetPos[0]>>TargetPos[1];

    Solution sb;
    int ans = sb.minStepToReachTarget(KnightPos, TargetPos, n);
    pr(ans);
    return 0;
}