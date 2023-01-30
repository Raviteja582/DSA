#include<bits/stdc++.h>
#include <vector>
using namespace std;

/**
    below algo is combination of path compression and union rank
    for union rank either use by height or size but don't call both.
*/

class Solution {
    private:
        int comp_size;
        vector<int> par;
        vector<int> rank_by_size;
        vector<int> rank_by_height;
    public: 
    Solution(){
        comp_size=100100;
        par.resize(100100);
        rank_by_size.resize(100100);
        rank_by_height.resize(100100);

    }
    explicit Solution(int n) {
        comp_size=n;
        rank_by_size.assign(n+1, 1);
        rank_by_height.assign(n+1, 0);
        par.resize(n+1);
        for(int i=0;i<=n;i++)
            par[i]=i;
    }

    int find(int x){
        if(x!=par[x]) par[x]=find(par[x]);
        return x;
    }

    int union_by_size(int x,int y){
        int a=find(x);
        int b=find(y);
        if(a!=b){
            if(rank_by_size[a] < rank_by_size[b]){
                rank_by_size[b]+=rank_by_size[a];
                par[a]=b;
            } else {
                rank_by_size[a]+=rank_by_size[b];
                par[b]=a;
            }
            comp_size--;
       }
       return comp_size;
    }

    int union_by_height(int x, int y){
        int a = find(x);
        int b = find(y);
        if(a!=b){
            if(rank_by_height[a]<rank_by_height[b]){
                par[a]=b;
                rank_by_height[b]++;
            } else {
                par[b]=a;
                rank_by_height[a]++;
            }
            comp_size--;
        }
        return comp_size;
    }
};

int main() {
    return 0;
}