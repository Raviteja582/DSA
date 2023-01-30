#include<bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<int> rv = { -1, 0, 1 };
    vector<int> cv = { 0, 1, -1 };
    int n, m;
    bool validCell(int i, int j){
        if(i>=0 && i<n && j>=0 && j<m)
            return true;
        return false;
    }

    void dfs(int row,int col, vector<vector<char>> &grid){
        grid[row][col]='#';
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int nxtRow = row+rv[i];
                int nxtCol = col+cv[j];
                if(validCell(nxtRow, nxtCol) && grid[nxtRow][nxtCol]=='1'){
                    dfs(nxtRow, nxtCol, grid);
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};

int main() {
    return 0;
}