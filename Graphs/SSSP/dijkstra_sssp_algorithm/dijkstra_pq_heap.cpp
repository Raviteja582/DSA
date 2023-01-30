/*
    Algo based on Normal Dijkstra using priority queue.
    T.C = O((E+V).log(E))
    S.C = O(E.log(E)) // number of times Edges pushed into the queue.
*/

#include<bits/stdc++.h>
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

class Dijkstra {
    private:
        vi dist;
        vector<vii> g;
        vector<int> p;
    public:
        Dijkstra(){
            dist.assign(100100, 1e18);
            p.assign(100100, -1);
            g.clear();
        }

        void createGraph(lli source, lli destination, lli weight){
            g[source].push_back({weight, destination});
            g[destination].push_back({weight, source});
        }

        void dijkstra_pq(lli sc){
            dist[sc]=0;
            priority_queue<ii> pq;
            pq.push(MP(-0, sc));
            while(!pq.empty()){
                ii fs = pq.top(); pq.pop();
                // check to see if it actual lesser node with min distance or older node with max distances.
                if(dist[fs.second] != -fs.first) 
                    continue;

                for(auto v:g[fs.S]){
                    lli neighbour = v.S;
                    lli weight = v.F;
                    if(dist[neighbour] > dist[fs.S]+weight){
                        dist[neighbour] = dist[fs.S]+weight;
                        p[neighbour]=fs.second;
                        pq.push(MP(-dist[neighbour], neighbour));
                    }
                }
            }
        }

        void dijkstra_set(int s) {
            dist[s]=0;
            set<pair<int, int>> q;
            q.insert({0, s});
            while (!q.empty()) {
                int v = q.begin()->second;
                q.erase(q.begin());
                for (auto edge : g[v]) {
                    int to = edge.first;
                    int len = edge.second;

                    if (dist[v] + len < dist[to]) {
                        q.erase({dist[to], to});
                        dist[to] = dist[v] + len;
                        p[to] = v;
                        q.insert({dist[to], to});
                    }
                }
            }
        }

        vector<int> restore_path(int s, int t, vector<int> const& p) {
            vector<int> path;
            for (int v = t; v != s; v = p[v])
                path.push_back(v);
            path.push_back(s);
            reverse(path.begin(), path.end());
            return path;
        }

        void printDist(int size){
            rep(i, 1, size)
                pr(i,dist[i]);
        }
};

int main() {
    Dijkstra d;
    int n, m;
    cin>>n>>m;
    fr(i, m){
        int x,y,w;
        cin>>x>>y>>w;
        d.createGraph(x, y, w);
    }
    int sc;
    cin>>sc;
    d.dijkstra_pq(sc);
    d.printDist(n);
    return 0;
}