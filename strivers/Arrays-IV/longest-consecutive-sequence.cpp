#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;

/**
Link: https://leetcode.com/problems/longest-consecutive-sequence/description/

Brute-force:
    for each element: (considering it as a starting point of the sequence)
        
        while(find(x+1)) {
            x+=1;
            count+=1
        }
        ans=max(ans,count);
    }

Optimizatio - 1:
    1. sort the given array;
    2. Maintain lastSmallest=INT_MIN and count=0;
        for i in (0,n):
            if arr[i]-1==lastSmallest: (i.e., previous element is present)
                lastSmallest = arr[i];
                count+1;
            else if arr[i]-1 != lastSmallest: (i.e., previous element is not present)
                lastSmallest = arr[i];
                count+1;
            ans=max(ans, count);

Optimal:
    Here we use unordered_set<int> and insert all the elements in it.
    while take each from the set:
        we decide whether the current ele is starting of any sequence by verifying ele-1 is in set
    if ele-1 is in set, then ignore this element
    else ele-1 is not in the set, then keep checking ele+1, ele+2, .... until the ele+k is found in the set.
*/


class Solution {
    public:

    /**
        optimal approach
    */
    int longestConsecutive(vector<int>& nums) {
        int ans=1;
        unordered_set<int> ss;
        for(auto x: nums) ss.insert(x);
        for(auto x: ss) {
            if(ss.find(x-1)==ss.end()) {
                int count=1;
                while(ss.find(x+1)!=ss.end())
                    count+=1, x+=1;
                ans=max(ans, count);
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}