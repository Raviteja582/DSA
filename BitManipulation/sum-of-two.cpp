#include <bits/stdc++.h>
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
	// using concept of half-adder
	int sum(int a, int b) {
		while(b!=0) {
			int c=(a&b)<<1;
			a=(a^b);
			b=c;
		}
		return a;
	}

	// using concept of half-subtractor
	int subtract(int a, int b) {
		// if a>b, ans is +ve else ans is -ve...

		while(b!=0) {
			int c=((~a)&b)<<1;
			a=(a^b);
			b=c;
		}
		return a;
	}

    int getSum(int a, int b) {
		if(a>=0 && b>=0)
			return sum(a,b);
		else if(a<0 && b<0)
			return -sum(abs(a), abs(b));
		else {
			int ta = (a<0) ? abs(a) : abs(b);
			int tb = (a>=0) ? a : b;
			int res = subtract(max(ta, tb), min(ta, tb));
			return (ta > tb) ? -res : res;
		}
	}
};

int main() {
    int a, b;
    cin>>a>>b;
    Solution sb;
    cout<<sb.getSum(a, b);
    return 0;
}