#include<bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
    public:
    int n;
    vector<vector<int>> adj;

    struct Edge {
        int w = INT_MAX;
        int to = -1;
    };

    void prim() {
        int total_weight = 0;
        vector<bool> selected(n, false);
        vector<Edge> min_e(n);
        min_e[0].w = 0;

        for (int i=0; i<n; ++i) {
            int v = -1;
            for (int j = 0; j < n; ++j) {
                if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
                    v = j;
            }

            if (min_e[v].w == INT_MAX) {
                cout << "No MST!" << endl;
                exit(0);
            }

            selected[v] = true;
            total_weight += min_e[v].w;
            if (min_e[v].to != -1)
                cout << v << " " << min_e[v].to << endl;

            for (int to = 0; to < n; ++to) {
                if (adj[v][to] < min_e[to].w)
                    min_e[to] = {adj[v][to], v};
            }
        }
        cout << total_weight << endl;
    }

};

int main() {

    return 0;
}