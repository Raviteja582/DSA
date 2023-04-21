//User function Template for C++
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n=nums.size();
        vector<int> ans(n+1);
        vector<int> lines(n+1);
        ans[n]=0;
        ans[n-1]=0;
        lines[n]=n;
        lines[n-1]=n;
        
        for(int i=n-2;i>=0;i--){
            int cost = INT_MAX, c=0;
            int currSpace=k;
            for(int j=i;j<n;j++){
                currSpace-=(nums[j]+c);
                if(currSpace>=0){
                    int currLineCost = currSpace * currSpace;
                    int futureCost = (lines[j+1]==n) ? 0 : ans[j+1];
                    int currCost = currLineCost + futureCost;
                    if(cost>currCost){
                        cost=currCost;
                        lines[i]=j+1;
                        if(lines[i]==n)
                            cost=0;
                    }
                    c=1;
                } else {
                    break;
                }
            }
            ans[i]=cost;
        }
        return ans[0];
    }
};