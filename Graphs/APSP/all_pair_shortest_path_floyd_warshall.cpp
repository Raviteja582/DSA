/**
 * Description: Floyd Warshall (Find the all pair shortest path distances)
 * Usage: See below O(N^3)
 * Source: https://github.com/dragonslayerx
 */
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int MAX = 100;
const int INF = 1e9 + 5;

void printpath(int i, int j, int n, int par[][MAX]){
    if(i!=j) printpath(i, par[i][j], n, par);
    cout<<j<<endl;
    return;
}

// undirected + weighted
int main(){
    int n;
    cin >> n;
    int Adj[MAX][MAX];
    int par[MAX][MAX];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            par[i][j]=i;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Adj[i][j] = INF;
        }
        Adj[i][i] = 0;
    }

    int countEdges;
    cin >> countEdges;
    for (int i = 0; i < countEdges; i++) {
        int a, b;
        int w;
        cin >> a >> b >> w;
        a--, b--;
        Adj[a][b] = min(Adj[a][b], w);
        Adj[b][a] = min(Adj[b][a], w);
    }

    int dist[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = Adj[i][j];
        }
    }
    // Floyd Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF and dist[k][j] < INF) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        par[i][j]=par[k][j];
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    // print shorted path from i->j
    int si,dj;
    cin>>si>>dj;
    printpath(si, dj, n, par);
}
