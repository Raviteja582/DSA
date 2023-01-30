#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};


class Solution {
    public:
    int n;
    vector<Edge> edges;
    int cost;

    void krushkal() {
        vector<int> tree_id(n);
        vector<Edge> result;
        cost=0;
        
        for (int i = 0; i < n; i++)
            tree_id[i] = i;

        sort(edges.begin(), edges.end());

        for (Edge e : edges) {
            if (tree_id[e.u] != tree_id[e.v]) {
                cost += e.weight;
                result.push_back(e);

                int old_id = tree_id[e.u], new_id = tree_id[e.v];
                for (int i = 0; i < n; i++) {
                    if (tree_id[i] == old_id)
                        tree_id[i] = new_id;
                }
            }
        }
    }
};

int main() {

    return 0;
}