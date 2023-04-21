#include <bits/stdc++.h>
using namespace std;

class StocksDP_AtMostK {
    /*
        1. we can do atmost k transactions.
        2. One transaction = One Buy + One Sell
        3. return max Profit.
    */

    /*
        There are 6 ways to do the problem
            1. First 3 ways are: using dp[ind][buy][count]:
                a) recursion without memorization
                b) recursion with memorization
                c) tabulation
            2. Second using : dp[ind][2*k+1] // odd is sell and even is buy
                a) recursion without memorization
                b) recursion with memorization
                c) tabulation
    */
    // I am only writing 2.c) way with tabulation code, which will be similar to DP-Stocks-III maxProfit_without_count_tabulation.

    int maxProfit_tabulation(
        int k,
        int n,
        int arr[]
    ) {
        // B S B S .... 2*k 
        // 0 is buy, 2*k-1 is Sell and 2*k is 0 no transaction
        int dp[2][2*k+1];
        memset(dp, 0, sizeof(dp));

        int ci=1;
        for(int i=n-1;i>=0;i--){
            for(int j=2*k-1;j>=0;j--){
                if(j%2) // sell
                    dp[ci][j] = max(
                        dp[1-ci][j+1] + arr[i],
                        dp[1-ci][j]
                    );
                else // buy
                    dp[ci][j] = max(
                        dp[1-ci][j+1] - arr[i],
                        dp[1-ci][j]
                    );
            }
            ci=1-ci;
        }

        return dp[1-ci][0];
    }

};