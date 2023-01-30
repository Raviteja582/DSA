/**
 * Descrption: BellmanFord (Finds the shortest path from source s to all vertices v. Detects a negative weight cycle if present.)
 * Usage: See below O(V E)
 * Source: https://github.com/dragonslayerx
 */
#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
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

const int MAX = 100;
const int INF = 1e9+5;

struct edges {
    int u;
    int v;
    long long w;
    edges(int u, int v, long long w): u(u), v(v), w(w) {}
};

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	vector<edges> edge;

	for (int i = 0; i < m; i++) {
		int a, b;
		long long w;
		scanf("%d%d%lld", &a, &b, &w);
		edge.push_back(edges(a, b, w));
	}

	int parent[MAX];
	long long dist[MAX];
	for (int i = 0; i < n; i++) {
		parent[i] = 0;
		dist[i] = INF;
	}

	dist[0] = 0; // distance of source node = 0
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (int)edge.size(); j++) {
			int u = edge[j].u;
			int v = edge[j].v;
			long long w = edge[j].w;
			if (dist[u] != INF) {
				if (dist[v] > dist[u] + w){
					dist[v] = dist[u] + w;
					parent[v] = u;
				}
			}
		}
	}

	bool negCycleExists = false;
	for (int j = 0; j < (int)edge.size(); j++) {
		int u = edge[j].u;
		int v = edge[j].v;
		long long w = edge[j].w;
		if (dist[v] > (dist[u] + w)) {
			negCycleExists = true;
			break;
		}
	}

	if (negCycleExists) {
        cout << "Negative Cycle Exists";
	} else {
        for (int i = 0; i < n; i++) {
            cout << i << "=>" << dist[i] << endl;
        }
	}
}
