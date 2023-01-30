#include<bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

class Cycle_Undirected_BFS {
    private:
    /*
        0 - un-visited node
        1 - visted node, in loop or queue
        2 - completey visited its neighbours.
    */
    vector<int> visit_status; // for both bfs and dfs
    queue<pair<int,int>> q; 
    public:

    bool bfs(int source, vector<int> adj[]) {
        visit_status[source] = 1;
        q.push({source, -1});
        while(!q.empty()){
            pair<int,int> pp = q.front(); q.pop();
            int ss=pp.first;
            int par=pp.second;
            visit_status[ss]=1;
            for(auto neigh: adj[ss]){
                if(!visit_status[neigh]) {
                    q.push({neigh, ss});
                } else if(neigh!=par) {
                    return true;
                }
            }
        }
        return false;
    }


    bool isCycle(int V, vector<int> adj[]) {
        visit_status.assign(V, 0);
        for(int i=0;i<V;i++){
            if(visit_status[i]==0 && bfs(i, adj))
                return true;
        }
        return false;
    }
};

class Cycle_Undirected_DFS {
    public:
    int n;
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> parent;
    int cycle_start, cycle_end;

    bool dfs(int v, int par) { // passing vertex and its parent vertex
        visited[v] = true;
        for (int u : adj[v]) {
            if(u == par) continue; // skipping edge to parent vertex
            if (visited[u]) {
                cycle_end = v;
                cycle_start = u;
                return true;
            }
            parent[u] = v;
            if (dfs(u, parent[u]))
                return true;
        }
        return false;
    }

    void find_cycle() {
        visited.assign(n, false);
        parent.assign(n, -1);
        cycle_start = -1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && dfs(v, parent[v]))
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

            cout << "Cycle found: ";
            for (int v : cycle)
                cout << v << " ";
            cout << endl;
        }
    }
};

int main() {
    return 0;
}

