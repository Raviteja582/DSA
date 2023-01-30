/**
    we can do this two ways:
    see in the Amazon notes.
*/

#include<bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
   public: 
   #define lli long long int

   vector<int> findRepeatedAndMissingNumber(const vector<int> &arr) {
    lli S1=0, S2=0;
    lli n = (lli)arr.size();

    // sum of numbers from 1..n
    S1 = (n*(n+1))/2;

    // sum of squares of 1...n
    /*
        M^2 - R^2 = S2;
    */
    S2 = (n*(2*n+1)*(n+1))/6;

    /*
        M - R = S1;  
    */
    for(lli i=0;i<n;i++) {
        S1-=(lli)arr[i];
        S2 -= (lli)arr[i] * (lli)arr[i];
    }

    /*
        M - R = S1;
        M^2 - R^2 = S2;
        (M+R)(M-R)=S2;
        M+R = S2/S1;
        M = (S1 + S2/S1)/2;
        R = M - S1;
    */
    lli missing = (S1 + S2/S1)/2;
    lli repeated = missing - S1;
    // gives error in local, but works in any platform
    // so commented for now
    // return vector<int>({missing, repeated});
    return vector<int>();
   }
};

int main() {
    return 0;
}