#include<bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

class Solution {
    public: 
    vector<int> g[100100];
    queue<int> q;
    vector<int> degree;
    vector<int> topo;
    int v, e;

    Solution(int n, int m){
        g->clear();
        v=n, e=m;
        
        topo.clear();
        degree.clear();
        q=queue<int>();

        degree.assign(n+1, 0);
    }

    void addEdge(){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        degree[b]++;
    }

    void topological_sort(){
        for(int i=1;i<=v;i++){
            if(degree[i]==0)
                q.push(i);
        }

        while(!q.empty()){
            int x=q.front(); q.pop();
            for(auto neigh: g[x]){
                degree[neigh]--;
                if(degree[neigh]==0)
                    q.push(neigh);
            }
            topo.push_back(x);
        }

        for(int i=0;i<(int)topo.size();i++)
            cout<<topo[i]<<" ";
        cout<<'\n';
    }
};

int main() {
    int n, m;
    cin>>n>>m;
    Solution sb(n,m);
    for(int i=0;i<m;i++) sb.addEdge();
    sb.topological_sort();
    return 0;
}