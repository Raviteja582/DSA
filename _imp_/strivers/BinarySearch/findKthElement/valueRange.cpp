#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int low = 0, high = max(arr1[n-1], arr2[m-1]);
        int ans = 0;
        while(low<=high) {
            int mid = (low+high)/2;
            int c1 = upper_bound(arr1, arr1+n, mid) - arr1;
            int c2 = upper_bound(arr2, arr2+m, mid) - arr2;
            if((c1+c2)<k){
                ans = mid+1;
                low=mid+1;
            } else 
                high=mid-1;
        }
        return ans;
    }
};

int main() {
    return 0;
}