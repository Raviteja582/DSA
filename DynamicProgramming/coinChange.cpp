#include<bits/stdc++.h>
#include <ios>
#include "../defines.cpp"
using namespace std;

class Solution {

    public:
        /*
            DP: dp(i, n) = dp(i-n)+dp(i, n-w[i])
        */
        long long int count(int s[], int m, int n){
            lli ans[n+1];
            mset(ans, 0LL);
            ans[0]=1;
            fr(i, m){
                rep(j, 0, n){
                    if(j-s[i] >= 0)
                        ans[j] = ans[j] + ans[j-s[i]];
                }
            }
            return ans[n];
        }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int arr[m];
        for(int i=0;i<m;i++) cin>>arr[i];
        Solution s;
        cout<<s.count(arr, m, n)<<endl;
    }
    return 0;
}
