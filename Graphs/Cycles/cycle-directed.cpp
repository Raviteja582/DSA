#include<bits/stdc++.h>
#include <vector>
using namespace std;

class Cycle_Directed_DFS {
    public:
    int n;
    vector<vector<int>> adj;
    vector<char> color;
    vector<int> parent;
    int cycle_start, cycle_end;

    bool dfs(int v) {
        color[v] = 1;
        for (int u : adj[v]) {
            if (color[u] == 0) {
                parent[u] = v;
                if (dfs(u))
                    return true;
            } else if (color[u] == 1) {
                cycle_end = v;
                cycle_start = u;
                return true;
            }
        }
        color[v] = 2;
        return false;
    }

    void find_cycle() {
        color.assign(n, 0);
        parent.assign(n, -1);
        cycle_start = -1;

        for (int v = 0; v < n; v++) {
            if (color[v] == 0 && dfs(v))
                break;
        }

        if (cycle_start == -1) {
            cout << "Acyclic" << endl;
        } else {
            vector<int> cycle;
            cycle.push_back(cycle_start);
            for (int v = cycle_end; v != cycle_start; v = parent[v])
                cycle.push_back(v);
            cycle.push_back(cycle_start);
            reverse(cycle.begin(), cycle.end());

            cout << "Cycle found: ";
            for (int v : cycle)
                cout << v << " ";
            cout << endl;
        }
    }
};


class Cycle_Directed_BFS {

    public: 
    vector<int> g[100100];
    queue<int> q;
    vector<int> degree;
    vector<int> topo;
    int v, e;

    Cycle_Directed_BFS(int n, int m){
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

        if(topo.size() < v) {
            cout<<"Cycle exists: "<<"\n";
            exit(0);
        }

        for(int i=0;i<(int)topo.size();i++)
            cout<<topo[i]<<" ";
        cout<<'\n';
    }
};

int main() {

    return 0;
}