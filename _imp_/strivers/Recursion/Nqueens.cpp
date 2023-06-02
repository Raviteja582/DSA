#include<bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:

    void findQueens(
        int col,
        vector<string> &board,
        vector<bool> &left,
        vector<bool> &tl,
        vector<bool> &bl,
        vector<vector<string>> &ans
    ) {
        int n=board.size();
        if(col==n) {
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++) {
            if(!left[row] && !tl[n-1+col-row] && !bl[row+col]) {

                left[row]=true;
                tl[n-1+col-row]=true;
                bl[row+col]=true;
                board[row][col]='Q';

                findQueens(col+1, board, left, tl, bl, ans);

                left[row]=false;
                tl[n-1+col-row]=false;
                bl[row+col]=false;
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        if(n==1) {
            return vector<vector<string>>({{"Q"}});
        }
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<bool> left(n, false), tl(2*n-2, false), bl(2*n-2, false);

        findQueens(0, board, left, tl, bl, ans);
        return ans;
    }
};

int main() {
    int n=4;
    Solution sb;
    vector<vector<string>> ans = sb.solveNQueens(n);
    for(auto vv: ans) {
        for(string ss: vv){
            cout<<ss<<"\n";
        }
        cout<<"\n\n";
    }
    return 0;
}