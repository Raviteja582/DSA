#include<bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    public:

    void findComb(
      int ind,
      vector<int> &curr,
      vector<vector<int>> &ans,
      vector<int> &arr,
      int tar
    ) {
      if(ind==arr.size()) {
        if(tar==0) {
          ans.push_back(curr);
        }
        return;
      }

      if(arr[ind]<=tar) {
        curr.push_back(arr[ind]);
        findComb(ind, curr, ans, arr, tar-arr[ind]);
        curr.pop_back();
      }

      findComb(ind+1, curr, ans, arr, tar);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        findComb(0, curr, ans, candidates, target);
        return ans;
    }
};

int main() {
  vector<int> arr({7,6,3,2});
  int tar=7;
  Solution sb;
  vector<vector<int>> ans = sb.combinationSum(arr, tar);
  for(auto vv: ans) {
    for(auto ee: vv)
      cout<<ee<<" ";
    cout<<"\n";
  }
  return 0;
}