#include<bits/stdc++.h>
#include <vector>
using namespace std;


vector<vector<pair<int,int>>> adj;

void BFS01(int s) {
    int n=adj.size();
    vector<int> d(n, 1e9+7);
    
    d[s] = 0;
    deque<int> q;
    q.push_front(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto edge : adj[v]) {
            int u = edge.first;
            int w = edge.second;
            if (d[v] + w < d[u]) {
                d[u] = d[v] + w;
                if (w == 1)
                    q.push_back(u);
                else
                    q.push_front(u);
            }
        }
    }
}