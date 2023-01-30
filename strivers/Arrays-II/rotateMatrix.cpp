#include<bits/stdc++.h>
#include <iostream>
#include <iterator>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

class Solution {
    public: 
    #define pp pair<int,int>

    void swapCorners(
        int index,
        vector<vector<int>> &arr
    ) {
        int n=arr.size();
        // top-row
        swap(arr[index][index], arr[index][n-index-1]);
        //left column
        swap(arr[index][index], arr[n-index-1][n-index-1]);
        //bottom row
        swap(arr[index][index], arr[n-index-1][index]);
        //right column
    }

    void swapDirection(
        pp p1, 
        pp p2, 
        int limit, 
        vector<vector<int>> dir,
        vector<vector<int>> &arr
    ) {
        for(int i=0;i<limit;i++){
            swap(arr[p1.first][p1.second], arr[p2.first][p2.second]);
            p1.first+=dir[0][0], p1.second+=dir[0][1];
            p2.first+=dir[1][0], p2.second+=dir[1][1];
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n==1)
            return;
        for(int i=0;i<n/2;i++){
            swapCorners(i,matrix);
            // right column
            swapDirection(
                make_pair(i, i+1),
                make_pair(i+1, n-i-1),
                n-2*(i+1),
                {{0,1},{1,0}},
                matrix
            );
            //bottom row
            swapDirection(
                make_pair(i, n-i-2),
                make_pair(n-i-1, i+1),
                n-2*(i+1),
                {{0,-1}, {0,1}},
                matrix
            );
            //left column
            swapDirection(
                make_pair(i, i+1),
                make_pair(n-i-2, i),
                n-2*(i+1),
                {{0,1}, {-1,0}},
                matrix
            );
        }
    }
};

int main() {
    int n;
    cin>>n;
    vector<vector<int>>v(n, vector<int>(n,0));

    for(int i=0;i<n;i++) 
        for(int j=0;j<n;j++)
            cin>>v[i][j];
    
    Solution sb;
    sb.rotate(v);
    cout<<"ans: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<v[i][j]<<" ";
        cout<<"\n";
    }
    cout<<endl;
    return 0;
}