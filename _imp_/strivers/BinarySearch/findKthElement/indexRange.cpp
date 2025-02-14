#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        // always do BS on lesser length array..
        if(m<n)
            return kthElement(arr2, arr1, m, n, k);

        /*
            arr1 -> n
            arr2 -> m
            n<m always
            no.of elements of arr1 <= arr2
        */
        /*
            if n=7, m=11 and k=15,
            then if take 0 from arr1, then we cannot take 15 from arr2,
            so there should a min elements needs to take from arr1, 
            i.e k-m elements, which are extra elements requiring in arr1 to reach k position.
        */
        int low=max(0,k-m);
        /*
            if n=7, m=11 and k=4
            then kth position will already present in arr1,
            so to consider arr2 elements we limit the range to k in arr1, such that
            we can take few from arr2.
        */
        int high=min(k,n), pos=k;
        
        while(low<=high) {

            int c1 = (low+high)>>1;
            int c2 = pos-c1;
            
            int l1 = c1==0 ? INT_MIN : arr1[c1-1];
            int l2 = c2==0 ? INT_MIN : arr2[c2-1];
            int r1 = c1==n ? INT_MAX : arr1[c1];
            int r2 = c2==m ? INT_MAX : arr2[c2];
            
            if(l1<=r2 && l2<=r1){
                return max(l1, l2);
            }
            if(l1>r2)
                high = c1-1;
            else
                low = c1+1;
        }
        return -1;
    }
};

int main() {
    return 0;
}