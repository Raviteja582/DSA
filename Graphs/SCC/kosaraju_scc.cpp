#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    //Function to find number of strongly connected components in the graph.
	void bfs1(int node, vector<bool> &vis, vector<int> *ord, vector<vector<int>> &graph) {
	    vis[node]=true;
	    for(auto neigh: graph[node]) {
	        if(!vis[neigh])
	            bfs1(neigh, vis, ord, graph);
	    }
	    
	    if(ord!=NULL)
	        (*ord).push_back(node);
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<vector<int>> adjR(V, vector<int>());
        for(int i=0;i<V;i++) {
            for(int j=0;j<adj[i].size();j++) {
                adjR[adj[i][j]].push_back(i);
            }
        }
        
        vector<bool> vis(V, false);
        vector<int> ord(V,0);
        for(int i=0;i<V;i++) {
            if(!vis[i])
                bfs1(i, vis, &ord, adj);
        }
        
        vis=vector<bool>(V, false);
        reverse(ord.begin(), ord.end());
        int ans=0;
        for(auto node: ord) {
            if(!vis[node]){
                ans+=1;
                bfs1(node, vis, NULL, adjR);
            }
        }
        
        return ans;
    }
};

int main() {

    return 0;
}