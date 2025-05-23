#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void solve(vector<int>& nums , int index , vector<vector<int>>& ans ){
        //base case
        if (index == nums.size()-1){
            ans.push_back(nums);
            return;
        }

        //recursive call
        for ( int i = index ; i<nums.size() ; i++){
            swap(nums[index] , nums[i]);
            solve(nums , index+1 , ans );
            swap(nums[index] , nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums , 0 , ans );
        return ans;
    }
};

int main() {

    return 0;
}