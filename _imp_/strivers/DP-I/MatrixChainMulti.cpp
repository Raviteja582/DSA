// link: https://leetcode.com/problems/maximum-product-subarray/

#include<bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    public:
    struct mc {
        int r, c, p;
        mc():r(-1), c(-1), p(-1){};
        mc(int r1, int c1, int p1): r(r1), c(c1), p(p1){};
    };

    int matrixMultiplication(int n, int arr[])
    {
        vector<vector<mc>> dp(n-1, vector<mc>(n-1, mc()));

        for(int i=0;i<n-1;i++) {
            dp[i][i]=mc(arr[i], arr[i+1], 0);
        }

        for(int len=2;len<n;len++) {
            
            for(int i=0, j=len-1; j<n-1; i++, j++) {
                mc m = mc(-1, -1, INT_MAX);
                for(int k=i;k<j;k++){
                    mc m1 = dp[i][k];
                    mc m2 = dp[k+1][j];

                    int cp = (m1.r * m1.c * m2.c) + m1.p + m2.p;
                    if(cp < m.p) {
                        m.p=cp;
                        m.r=m1.r;
                        m.c=m2.c;
                    }
                }
                dp[i][j]=m;
            }
        }

        return dp[0][n-2].p;
    }
};

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    Solution sb;
    cout<<sb.matrixMultiplication(n, arr);
    return 0;
}