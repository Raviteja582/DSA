#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  /*
      Buy Stock and Sell with a transaction fee...

      Solution:
          During Sell you can deduct the fee or
          during buy you can deduct the fee...
  */

  int maxProfit_tabulation(int n, const int arr[], const int fee) {
    int dp[2][2];
    memset(dp, 0, sizeof(dp));

    int ci = 1;
    for (int i = n - 1; i >= 0; i--) {
      dp[ci][0] = max(arr[i] + dp[1 - ci][1] - fee, dp[1 - ci][0]); // sell
      dp[ci][1] = max(dp[1 - ci][0] - arr[i],
                      dp[1 - ci][1]); // buy, here also you can pay fee.
      ci = 1 - ci;
    }
    return dp[1 - ci][1];
  }
};

int main() { return 0; }