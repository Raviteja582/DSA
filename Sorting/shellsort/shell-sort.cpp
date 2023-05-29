#include<bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    public:

    void shellSort(vector<int> &arr) {
        int n=arr.size();
        for(int gap=n/2; gap>0; gap/=2) {
            // perform insertion sort at gap;
            for(int i=gap;i<n;i++) {
                // traverse back with j as same as insertion sort
                // but maintain gap
                int tmp = arr[i];
                int j;
                for(j=i; j>=gap && arr[j-gap]>tmp; j-=gap)
                    arr[j]=arr[j-gap];
                arr[j]=tmp;
            }
        }
    }
};

int main() {

    return 0;
}