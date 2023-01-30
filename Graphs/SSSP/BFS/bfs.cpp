#include<bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

class Solution {
    public:
    int n;
    vector<vector<int>> adj;

    void bfs(
        int s, // source to perform BFS
        int u // finding path from source to random vertex u.
    ) {

        vector<bool> used(n);
        vector<int> d(n), p(n);
        queue<int> q;

        q.push(s);
        used[s] = true;
        p[s] = -1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : adj[v]) {
                if (!used[u]) {
                    used[u] = true;
                    q.push(u);
                    d[u] = d[v] + 1;
                    p[u] = v;
                }
            }
        }

        // path
        if (!used[u]) {
            cout << "No path!";
        } else {
            vector<int> path;
            for (int v = u; v != -1; v = p[v])
                path.push_back(v);
            reverse(path.begin(), path.end());
            cout << "Path: ";
            for (int v : path)
                cout << v << " ";
        }
    }
};

int main() {

    return 0;
}