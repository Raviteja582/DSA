#include<bits/stdc++.h>
#include <vector>
using namespace std;

#define debarr(a, n)  cout << #a << " : "; for (int i = 0; i < n; i++) cerr << a[i] << " ";cerr << endl;
#define debmat(mat, row, col) cout << #mat << " :\n"; for (int i = 0; i < row; i++) { for (int j = 0; j < col; j++) cerr << mat[i][j] << " "; cerr << endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T> ostream &operator<<(ostream &os, const pair<S, T> &p) { return os << "(" << p.first << ", " << p.second << ")";}
template <class T> ostream &operator<<(ostream &os, const vector<T> &p) {os << "[ ";for (auto &it : p)os << it << " ";return os << "]"<<endl;}
template <class T> ostream &operator<<(ostream &os, const unordered_set<T> &p) {os << "[ ";for (auto &it : p)os << it << " ";return os << "]" <<endl;}
template <class S, class T> ostream &operator<<(ostream &os, const unordered_map<S, T> &p) {os << "[ ";for (auto &it : p)os << it << " ";return os << "]" << endl;}
template <class T> ostream &operator<<(ostream &os, const set<T> &p) {os << "[ ";for (auto &it : p)os << it << " ";return os << "]" << endl;}
template <class T> ostream &operator<<(ostream &os, const multiset<T> &p) {os << "[ ";for (auto &it : p)os << it << " ";return os << "]" << endl;}
template <class S, class T> ostream &operator<<(ostream &os, const map<S, T> &p) {os << "[ ";for (auto &it : p)os << it << " ";return os << "]" << endl;}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(',');cerr << str.substr(0, idx) << " : " << t << ",";dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "[";for (T i = a; i != b; ++i) {if (i != a)cerr << ", ";cerr << *i;}cerr << "]\n";}


/*
	For small n, we can use the Pascal triangle method for nCr.
	and since we are only using addition operation, it can work with any modulo.
*/
class Solution {
	public:
	
	// based on this approach, below calculation is done.
	vector<vector<int>> printPascalTriangle(int n) {
		vector<vector<int>> vv;
		vv.push_back({1});
		for(int i=1;i<=n;i++) {
			vv.push_back(vector<int>(i+1, 1));
			for(int j=1;j<i;j++) {
				vv[i][j] = vv[i-1][j-1]+vv[i-1][j];
			}
		}
		return vv;
	}

	// use case:
	// 1. If n<10^3 and r<10^3 we can precompute all and use for multiple queries.
	// T.C: O(n^2) and S.C: O(r)
	int nCrWithPascal(int n, int r) {
		if(n<0 || r<0 || n<r)
			return 0;
		if(n==0 || r==0 || n==r) 
			return 1;
			
		vector<vector<int>> v(2, vector<int>());
		v[0].assign(1, 1);
		int ci=1;
		for(int i=1;i<=n;i++) {
			v[ci].assign(min(i+1,r+1), 1);
			for(int j=1; (i<=r) ? j<r:j<=r;j++){
				v[ci][j]=v[1-ci][j-1]+v[1-ci][j];
			}
			// debarr(v[ci], min(i+1, r+1));
			ci=1-ci;
		}
		return v[1-ci][r];
	}

	// use case: 
	// 1. use when n>10^3 and r>10^3
	// T.C: O(n*r) and S.C: O(r)
	int nCrWithPascal_Optimised(int n, int r){
		if(r<0 || n<0 || n<r) return INT_MIN;
		if(r==0 || n==0 || n==r) return 1;
		
		r = min(n-r, r);
		int ncr[r+1];
		memset(ncr, 0, sizeof(ncr));

		ncr[0]=1; ncr[1]=1;

		for(int i=2;i<=n;i++){
			for(int j=min(i,r);j>0;j--){
				ncr[j] = ncr[j-1] + ncr[j];
			}
		}

		return ncr[r];
	}
};

int main() {
	Solution sb;
	vector<vector<int>> vv = sb.printPascalTriangle(7);
	for(auto xx: vv){
		for(auto x: xx)
			cout<<x<<" ";
		cout<<"\n";
	}

	int nCr_1 = sb.nCrWithPascal_Optimised(2, 1);
	pr(nCr_1);
    return 0;
}