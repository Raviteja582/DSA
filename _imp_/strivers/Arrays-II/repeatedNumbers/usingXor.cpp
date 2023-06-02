#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
    Check implementation details in Amazon notes...
*/

class Solution {
public:

  vector<int> findRepeatedAndMissingNumber(const vector<int> &arr) {
    int x = 0, x1 = 0, x0 = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      x ^= arr[i];
    }
    /*
        M ^ R = x;
    */
    for (int i = 1; i <= n; i++) {
      x ^= i;
    }

    // find LSB(right side) in binary expansion of X.
    int pos = x & ~(x - 1);
    
    for (int i = 0; i < n; i++) {
      if (arr[i] & pos)
        x1 ^= arr[i];
      else
        x0 ^= arr[i];
    }

    for (int i = 1; i <= n; i++) {
      if (i & pos)
        x1 ^= i;
      else
        x0 ^= i;
    }

    for (int i = 0; i < n; i++) {
      if (x1 == arr[i])
        return vector<int>({x1, x0});
      if (x0 == arr[i])
        return vector<int>({x0, x1});
    }
    return vector<int>();
  }
};
int main() {
    Solution sb;
    return 0;
}