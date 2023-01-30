#include<bits/stdc++.h>
#include <climits>
#include <queue>
#include <vector>
using namespace std;

// undirected + unweighted
vector<vector<int>> graph;
void bfs_undirected(int node, int n,int &ans){
    vector<int> dist(n+1,INT_MAX);
    dist[node]=0;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int curr = q.front();q.pop();
        for(auto neigh: graph[curr]){
            if(dist[neigh]==INT_MAX) {// unvisited node.
                dist[neigh]=dist[curr]+1;
                q.push(neigh);
            }
            // back edge: because this node already in queue by the curr parent.
            else if(dist[neigh]>=dist[curr]){
                ans= min(ans, dist[neigh]+dist[curr]+1);
            }
        }
    }
}


// directed+unweighted
void bfs_weighted(int node, int n, int &ans) {
    vector<int> dist(n+1, INT_MAX);
    dist[node]=0;
    queue<int> q;
    q.push(node);
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        for(auto neigh: graph[curr]) {
            if(neigh==node) { // directed back to the source node...
                ans = min(ans, dist[curr]+1);
            }
            // unvisited node...
            else if(dist[neigh]==INT_MAX) {
                dist[neigh] = dist[curr]+1;
                q.push(neigh);
            }
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    graph.assign(n+1, vector<int>());
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int ans=n+1;
    for(int i=1;i<=n;i++)
        bfs_undirected(i,n,ans);
    if(ans==n+1)
        cout<<"no cycle";
    else
        cout<<"cycle length:"<<ans;
    return 0;
}