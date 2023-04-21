#include <bits/stdc++.h>
#include <vector>
using namespace std;

class StocksDP_AtMostTwo {
    /*
        1. Atmost 2 transactions are allowed to do.
        2. One Buying + one Selling is called a transaction.
        3. return maximum profit.
    */

    public:

    /*
        -> T.C = O(2^N)
        -> S.C = O(2^N) recursion stack space.
    */
    int maxProfit_recursion_without_memorization(
        int ind,
        int buy,
        int count,
        int n,
        int arr[]
    ) {
        // either stocks over or atmost two transaction are over....
        if(ind==n || count==0)
            return 0;

        if(buy)
            return max(
                maxProfit_recursion_without_memorization(ind+1, false, count, n, arr) - arr[ind],
                maxProfit_recursion_without_memorization(ind+1, true, count, n, arr)
            );
        
        return max(
            maxProfit_recursion_without_memorization(ind+1, true, count-1, n, arr) + arr[ind],
            maxProfit_recursion_without_memorization(ind+1, false, count, n, arr)
        );
    }

    /*
        T.C = O(N*2*2)
        S.C = O(N*2*2) + O(N)
    */
    int maxProfit_recursion_with_memorization(
        int ind,
        int buy,
        int count,
        int n,
        int arr[],
        vector<vector<vector<int>>> &v
    ) {
        if(ind == n || count == 0)
            return 0;
        
        if(v[ind][buy][count] != -1)
            return v[ind][buy][count];
        
        if(buy)
            v[ind][buy][count] = max(
                maxProfit_recursion_with_memorization(ind+1, false, count, n, arr, v) - arr[ind],
                maxProfit_recursion_with_memorization(ind+1, true, count, n, arr, v)
            );
        else
            v[ind][buy][count] = max(
                maxProfit_recursion_with_memorization(ind+1, true, count-1, n, arr, v) + arr[ind],
                maxProfit_recursion_with_memorization(ind+1, false, count, n, arr, v)
            );
        return v[ind][buy][count];
    }

    int maxProfit_tabulation(
        int n,
        int arr[]
    ){
        // atmost two = either 1 or 2 so size is 3.
        int dp[2][2][3];
        
        for(int i=0;i<2;i++) // LCS optimised array
            for(int j=0;j<2;j++) // Buy or sell
                for(int k=0;k<3;k++) // no.of transactions
                    dp[i][j][k]=0;
        
        int ci=1;
        for(int i=n-1;i>=n;i++){
            for(int count=1;count<=2;count++){
                dp[ci][0][count] = max(
                    dp[1-ci][1][count-1] + arr[i],
                    dp[1-ci][0][count]
                );
                dp[ci][1][count] = max(
                    dp[1-ci][0][count] - arr[i],
                    dp[1-ci][1][count]
                );
            }
            ci=1-ci;
        }
        return dp[1-ci][1][2];
    }


    /*
        further optimization process:
            if atmost two transactions : 0-Buy 1-Sell 2-Buy 3-Sell
            So in even we buy and move to odd for sell
            and in odd we sell and move to even to buy.
    */
    /*
        recursion expression look like:
            dp(int ind, int pos, int n, int arr){
                if(ind == n || pos == 4)
                    return 0;
                
                if(pos%2) // sell
                    return max(
                        dp(ind+1, pos+1, n, arr) + arr[ind],
                        dp(ind+1, pos, n, arr)
                    );
                
                // buy
                return max(
                    dp(ind+1, pos+1, n, arr) - arr[ind],
                    dp(ind+1, pos, n, arr)
                )
            }
            for this method also we have:
                recursion without memorization dp(ind, pos)
                recursion with memorization dp(ind, pos, dp[ind][pos])
                tabulation with optimization which is below.
    */
    int maxProfit_without_count_tabulation(int n, int arr[]) {

        int dp[2][4];
        // outside the stock the values are 0
        memset(dp, 0, sizeof(dp));

        int ci=1;
        for(int i=n-1;i>=0;i--){
            for(int j=3;j>=1;j--){
                if(j%2) // sell
                    dp[ci][j] = max(
                        dp[1-ci][j+1]+arr[i],
                        dp[1-ci][j]
                    );
                else
                    dp[ci][j] = max(
                        dp[1-ci][j+1]-arr[i],
                        dp[1-ci][j]
                    );
            }
            ci=1-ci;
        }

        return dp[1-ci][0];
    }
};
