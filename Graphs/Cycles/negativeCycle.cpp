#include<bits/stdc++.h>
#include <vector>
using namespace std;

struct Edge {
    int a, b, cost;
};
/*
    Can be used in: Find any cycle of negative weight in it, if such a cycle exists.
*/
class BellmonFord_Algo {
    public:
    int n, m;
    vector<Edge> edges;
    const int INF = 1000000000;

    void solve()
    {
        vector<int> d(n);
        vector<int> p(n, -1);
        d[0]=0;
        int x;
        for (int i = 0; i < n; ++i) {
            x = -1;
            for (Edge e : edges) {
                if (d[e.a] + e.cost < d[e.b]) {
                    d[e.b] = d[e.a] + e.cost;
                    p[e.b] = e.a;
                    x = e.b;
                }
            }
        }

        if (x == -1) {
            cout << "No negative cycle found.";
        } else {
            for (int i = 0; i < n; ++i)
                x = p[x];

            vector<int> cycle;
            for (int v = x;; v = p[v]) {
                cycle.push_back(v);
                if (v == x && cycle.size() > 1)
                    break;
            }
            reverse(cycle.begin(), cycle.end());

            cout << "Negative cycle: ";
            for (int v : cycle)
                cout << v << ' ';
            cout << endl;
        }
    }
};

/*
    can be used as:  find all pairs of vertices which have a path of arbitrarily small weight between them.
*/
class FloydWarshall_Algo {
    public:
    int n;
    const int INF = 1000000000;
    vector<vector<int>> adj;

    void solve() {
        vector<vector<int>> d(n, vector<int>(n, INF));

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                d[i][j]=adj[i][j];
            }
            d[i][i]=0;
        }

        for(int k=0;k<n;k++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(d[i][k]<INF && d[k][j]<INF)
                        if(d[i][j] > d[i][k] + d[k][j])
                            d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int t = 0; t < n; ++t) {
                    if (d[i][t] < INF && d[t][t] < 0 && d[t][j] < INF)
                        d[i][j] = - INF; 
                }
            }
    }
}


};

int main() {

    return 0;
}