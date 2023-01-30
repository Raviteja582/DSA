#include<bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    public:
    int findNthElement(vector<int> &a, vector<int> &b, int k){
        int n=a.size(), m=b.size();
        int low, high;
        // one of them will be empty...
        if(n!=0 && m!=0){
            low=min(a[0], b[0])-1;
            high=max(a[n-1], b[m-1]);
        } else if(n==0){
            low=b[0]-1;
            high=b[m-1];
        } else{
            low=a[0]-1;
            high=a[n-1];
        }
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            int c1 = upper_bound(a.begin(), a.end(), mid)-a.begin();
            int c2 = upper_bound(b.begin(), b.end(), mid)-b.begin();
            if((c1+c2)<k){
                ans= mid+1;
                low=mid+1;
            } else {
                high=mid-1;
            }
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans=0.00000;
        int n=nums1.size(), m=nums2.size();
        if((n+m)&1) {
            int k = (n+m)/2 + 1;
            ans = (double)findNthElement(nums1, nums2, k);
            return ans;
        } else {
            int k = (n+m)/2;
            ans = (double)findNthElement(nums1, nums2, k) + (double)findNthElement(nums1, nums2, k+1);
            ans = ans/2;
            return ans;
        }
    }
};

int main() {
    return 0;
}