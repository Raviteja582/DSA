#include<bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<int> col;
    bool dfs(int node, int from, int color, vector<int> adjL[]){
        col[node]=color;
        for(auto neigh:adjL[node]){
            if(neigh!=from){
                if(
                    (col[neigh]==-1 && !dfs(neigh, node, 1-color, adjL)) ||
                    col[neigh]==col[node]
                )
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<int>adj[]){
        col.assign(V, -1);
        for(int i=0;i<V;i++){
            if(
                col[i]==-1 &&
                !dfs(i,i,0,adj)
            ){
                return false;
            }
        }
        return true;
	}
};

int main() {
    return 0;
}