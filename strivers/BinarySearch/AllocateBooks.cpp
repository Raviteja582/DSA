#include<bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    public: 
    bool check(vector<int> &arr, int B, long long mid) {
        int n = arr.size(), s=0;
        long long curr=0;
        for(int i=0;i<n;i++){
            if((curr+arr[i])<=mid){
                curr+=arr[i];
            } else{
                s++;
                curr=arr[i];
                if(curr>mid) return false;
            }
        }
        if(curr<=mid) {
            s++;    
            return s<=B;
        }
        return false;
    }

    int books(vector<int> &A, int B) {
       int n = A.size();
        if(n<B) return -1;
        
        long long ans=-1, low=INT_MAX, high=0, mid;
        for(int i=0;i<n;i++) {
            low = min(low, (long long)A[i]);
            high = high + (long long)A[i];
        }
        
        while(low<=high) {
            mid = (low+high)/2;
            if(check(A, B, mid)){
                ans=mid;
                high=mid-1;
            } else
                low=mid+1;
        }
        return ans; 
    }
};

int main() {
    int n;cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++) cin>>arr[i];
    int b;cin>>b;
    Solution sb;
    cout<<sb.books(arr,b);
    return 0;
}