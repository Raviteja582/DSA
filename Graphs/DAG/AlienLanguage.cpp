#include<bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

#define IGNORE cin.ignore(INT_MAX,'\n')

class Solution {
    public: 
    vector<int> deg;
    vector<vector<int>> graph;
    string findOrder(string dict[], int N, int K) {
        string ans="";
        queue<int> q;

        deg.assign(26, -1);
        graph.assign(26, vector<int>());

        // creating graph based on sort order of strings
        for(int i=0;i<N-1;i++){
            size_t limit = min(dict[i].size(), dict[i+1].size());
            for(int j=0;j<limit;j++){
                if(dict[i][j] != dict[i+1][j]){
                    // assigning degree 
                    int source=dict[i][j]-'a';
                    int destination=dict[i+1][j]-'a';
                    if(deg[destination]==-1)
                        deg[destination]=1;
                    else
                        deg[destination]+=1;
                    if(deg[source]==-1)
                        deg[source]=0;

                    // graph edge
                    graph[source].push_back(destination);
                    break;
                }
            }
        }

        // push charcters which have in-degree as 0
        for(int i=0;i<26;i++)
            if(deg[i]!=-1 && deg[i]==0) q.push(i);

        // bfs 
        while(!q.empty()){
            int source = q.front(); q.pop();
            ans.push_back('a'+source);
            for(auto neigh: graph[source]){
                deg[neigh]-=1;
                if(deg[neigh]==0)
                    q.push(neigh);
            }
        }

        return ans;
    }
};

int main() {
    int n,k;
    cin>>n>>k;
    string str[n];
    for(int i=0;i<n;i++)
        cin>>str[i];
    Solution sb;
    cout<<sb.findOrder(str, n, k);
    return 0;
}