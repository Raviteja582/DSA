#include<bits/stdc++.h>
#include <vector>
using namespace std;

// Link: https://www.youtube.com/watch?v=bNvIQI2wAjk&themeRefresh=1&theme=dark
class Solution {
    public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        ans[0]=1;
        int pre=1;
        for(int i=1;i<nums.size();i++) {
            pre *= nums[i-1];
            ans[i]=pre;
        }
        int post = nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--) {
            ans[i]*=post;
            post*=nums[i];
        }
        return ans;
    }
};

int main() {
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution sb;
    vector<int> ans = sb.productExceptSelf(arr);
    for(auto x: ans) cout<<x<<" ";
    return 0;
}