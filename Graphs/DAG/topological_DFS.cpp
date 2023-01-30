#include<bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    public: 
    vector<int> g[100100];
    vector<int> topo;
    vector<int> vis;
    int v, e;

    Solution(int n, int m){
        v=n, e=m;
        g->clear();
        topo.clear();
        vis.clear();
        vis.assign(n+1, 0);
    }

    void addEdge(){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }

    void topological_sort(){
        for(int i=1;i<=v;i++){
            if(!vis[i])
                dfs(i);
        }
    }

    void dfs(int node){
        vis[node] = 1;
        for(auto x: g[node]){
            if(!vis[x])
                dfs(x);
        }
        topo.push_back(node);
    }

    void printPath(){
        reverse(topo.begin(), topo.end());
        for(int i=0;i<(int)topo.size();i++)
            cout<<topo[i]<<" ";
        cout<<'\n';
    }
};

int main() {
    int n, m;
    cin>>n>>m;
    Solution sb(n, m);
    for(int i=0;i<m;i++) sb.addEdge();
    sb.topological_sort();
    sb.printPath();
    return 0;
}