#include <bits/stdc++.h>
#include "../../../Heaps_PriorityQueue/binary_heap/binary_heap.h"
using namespace std;
#define INF 999999

#define ll long long
#define vpp vector<pair<ll, ll>>
vector<bool> marked;
/*
    Works on sparse garphs.
    Implemention using priority_queue,
    please check prims_sparse.cpp for set implemention on sparse graphs
    and prims_dense.cpp for dense graphs.
*/
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int tw = 0;
        vector<int> min_w(V, INT_MAX);
        vector<bool> vis(V, false);
        min_w[0]=0;
        
        priority_queue<pair<int,int>> q;
        q.push({-0, 0});
        for(int i=0;i<V;i++) {
            pair<int,int> p1 = q.top(); q.pop();
            if(vis[p1.second]) {
                i--;
                continue;
            }
            int dist = -p1.first;
            tw+=dist;
            vis[p1.second]=true;
            // cout<<dist<<" "<<p1.second<<"\n";
            for(auto neigh: adj[p1.second]) {
                if(!vis[neigh[0]] && (min_w[neigh[0]] > neigh[1])) {
                    min_w[neigh[0]] = neigh[1];
                    q.push({-min_w[neigh[0]], neigh[0]});
                }
            }
        }
        return tw;
    }
};