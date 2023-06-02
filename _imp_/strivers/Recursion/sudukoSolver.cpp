#include<bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    public:

    bool isPossible(
        vector<vector<char>> &board,
        char c,
        int row,
        int col
    ) {
        for(int i=0;i<9;i++) {
            if(
                board[row][i]==c ||
                board[i][col]==c ||
                board[3*(row/3)+i/3][3*(col/3)+i%3]==c
            ) return false;
        }
        return true;
    }

    bool findBoard(
        vector<vector<char>> &board
    ) {
        for(int row=0;row<9;row++) {
            for(int col=0;col<9;col++) {
                if(board[row][col]=='.') {
                    for(int i='1';i<='9';i++){
                        if(isPossible(board, i, row, col)) {
                            board[row][col]=i;                        
                            if(findBoard(board))
                                return true;
                            board[row][col]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        findBoard(board);
        for(auto vv: board) {
            for(char c: vv) {
                cout<<c<<" ";
            }
            cout<<"\n";
        }
    }
};

int main() {

    return 0;
}