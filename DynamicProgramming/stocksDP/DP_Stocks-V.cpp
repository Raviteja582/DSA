#include <bits/stdc++.h>
#include <cstring>
using namespace std;

class Solution {
public:
  /*
      Buy stock and sell with Cooldown...
      Cooldown: Cannot buy immediately right after sell


      Solution:
          - It is similar to the DP-II, but the only condition is we not allowed
     to buy after a sell.
          - So in Sell condition, when we move to the ind+1 for a buy, we just
     move to ind+2

        here it is not recommended to do the LCS - space optimization as we are
     ind+2 indexes...
  */

  int maxProfit_tabulation(int n, const int arr[]) {
    int dp[n + 2][2];
    memset(dp, 0, sizeof(dp));

    for (int i = n - 1; i >= 0; i--) {
      dp[i][1] = max(dp[i + 1][0] - arr[i], dp[i + 1][1]);
      dp[i][0] = max(arr[i] + dp[i + 2][1],
                     dp[i + 1][0]); // here are buying from i+2 index...
    }

    return dp[0][1];
  }
};

int main() { return 0; }