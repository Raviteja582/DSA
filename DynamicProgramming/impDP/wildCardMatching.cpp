#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
/*You are required to complete this method*/

    #define debmat(mat, row, col) cout << #mat << " :\n"; for (int i = 0; i < row; i++) { for (int j = 0; j < col; j++) cerr << mat[i][j] << " "; cerr << endl;}
    int wildCard(string pattern, string str) {
        int n = str.size(), m = pattern.size();
        bool dp[2][n + 1];
        if(pattern[0]=='*')
            for(int i=0;i<=n;i++)
                dp[0][i]=true;
        else if(pattern[0]=='?'){
            for(int i=0;i<=n;i++)
                dp[0][i]=false;
            dp[0][1] = true;
        }
        else{
            dp[0][0]=false;
            dp[0][1]=(pattern[0]==str[0]);
            for(int i=2;i<=n;i++)
                dp[0][i]=false;
        }
        for(int i=0;i<=n;i++)
            dp[1][i]=false;
        int currInd = 0;
        for (int i = 1; i < m; i++) {
            currInd=i&1;
            for (int j = 1; j <= n; j++) {
                if(isalnum(str[j-1])==0)
                    return 0;
                if (pattern[i] == '?')
                    dp[currInd][j] = dp[1-currInd][j-1];
                else if (pattern[i] == '*')
                    dp[currInd][j] = dp[1-currInd][j - 1] || dp[1-currInd][j] || dp[currInd][j-1];
                else
                    dp[currInd][j] = (pattern[i] == str[j - 1]) ? dp[1-currInd][j - 1] : false;
            }
        }
        return dp[currInd][n];
    }
};