#include<bits/stdc++.h>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
    // only track whether we are placing in current column upside
    // because we move row by row from top to bottom and left to right
    vector<bool> col;
    // left diagoal: right top -> bottom left: row+col
    vector<bool> left; 
    // right diagonal: left top -> bottom right: (col-row)+n-1
    vector<bool> right;
    int ans;

    vector<vector<char>> grid;

    Solution() {
        col=vector<bool>(8,false);
        left=vector<bool>(16, false);
        right=vector<bool>(16, false);
        grid=vector<vector<char>>(8, vector<char>(8, ' '));
        ans=0;
        for(int i=0;i<8;i++){
            string ss;
            cin>>ss;
            for(int j=0;j<8;j++)
                grid[i][j]=ss[j];
        }
    }

    bool isSafe(int r, int c) {
        return r<8 && c<8 && !(col[c] || left[r+c] || right[(c-r)+7]) && grid[r][c]=='.';
    }

    void rec(int row) {
        if(row>=8) {
            ans+=1;
            return;
        }

        for(int i=0;i<8;i++) {
            if(isSafe(row, i)) {
                col[i]=true;
                left[row+i]=true;
                right[(i-row)+7]=true;
                rec(row+1);
                col[i]=false;
                left[row+i]=false;
                right[(i-row)+7]=false;
            }
        }
    }
};

int main() {
    Solution sb;
    sb.rec(0);
    cout<<sb.ans<<endl;
    return 0;
}