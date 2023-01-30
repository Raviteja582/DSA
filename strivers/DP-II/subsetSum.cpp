#include<bits/stdc++.h>
using namespace std;


// intution based approach 
// better time & spaceComplexity than 1D-DP
class Solution {
    public:
    template <int N>
    bool canPartitionN(vector<int>& nums, int target) {
        using Set = bitset<N + 1>;
        Set cur;
        cur.set(0);
        for (int val : nums) {
            cur |= cur << val;
            if (cur[target]) {
                return true;
            }
        }
        return false;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int val : nums) {
            sum += val;
        }
        if (sum % 2 != 0) {
            return false;
        }

        int N = sum / 2;
        return canPartitionN<10000>(nums, N);
        
        // testing the range of sum/2;
        if (N <= 100) {
            return canPartitionN<100>(nums, N);
        } else if (N <= 500) {
            return canPartitionN<500>(nums, N);
        } else if (N <= 1000) {
            return canPartitionN<1000>(nums, N);
        } else if (N <= 2000) {
            return canPartitionN<2000>(nums, N);
        } else if (N <= 4000) {
            return canPartitionN<4000>(nums, N);
        } else if (N <= 6000) {
            return canPartitionN<6000>(nums, N);
        } else if (N <= 8000) {
            return canPartitionN<8000>(nums, N);
        } else {
            return canPartitionN<10000>(nums, N);
        }
    }
};

int main() {

    return 0;
}