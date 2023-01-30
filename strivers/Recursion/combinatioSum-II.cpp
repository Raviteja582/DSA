#include <algorithm>
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
      if(tar==0) {
        ans.push_back(curr);
        return;
      }

      for(int i=ind; i<arr.size();i++) {
        if(i!=ind && arr[i]==arr[i-1]) continue;
        if(arr[i]>tar) break;
        curr.push_back(arr[i]);
        findComb(i+1, curr, ans, arr, tar-arr[i]);
        curr.pop_back();
      }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;

        findComb(0, curr, ans, candidates, target);
        return ans;
    }
};

int main() {
  vector<int> arr({10, 1, 2,7,6,1,5});
  int tar=8;
  Solution sb;
  vector<vector<int>> ans = sb.combinationSum2(arr, tar);
  for(auto vv: ans) {
    for(auto ee: vv)
      cout<<ee<<" ";
    cout<<"\n";
  }
  return 0;
}