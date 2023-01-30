#include <bits/stdc++.h>
#include "../defines.cpp"
#include <climits>
#include <cstring>
#include <unordered_map>
#include <utility>
using namespace std;

/*

Problem Link:
https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?page=1&status[]=unsolved&curated[]=4&sortBy=submissions
*/
class Solution
{
public:
    typedef pair<int, int> p;
    typedef pair< pair<int, int>, int> pp;
    typedef vector<p> vp;
    typedef vector<vector<pp>> xp;
    
    /*
        m[ (l,r) ] = { (row, col), prod }; 
    */
    xp memo;
    vp pairs;

    void dp(int l, int r){

        // cout<<"\n("<<l<<", "<<r<<") -> ";
        if(l==r){
            pp curr = make_pair(pairs[l], 0);
            memo[l][r] = curr;
        } else if(memo[l][r].second == -1){
            int ans = INT_MAX;
            for(int i=l;i<r;i++){

                if( memo[l][i].second == -1 )
                    dp(l, i);
                if( memo[i+1][r].second == -1)
                    dp(i+1, r);

                // Cost for Multiplication.
                int lCal = memo[l][i].second;
                int rightCal = memo[i+1][r].second;
                int currCal = (memo[l][i].first.first * memo[l][i].first.second)*memo[i+1][r].first.second;
                int total = lCal + rightCal + currCal;

                if(ans > total){
                    pp curr = make_pair(make_pair(memo[l][i].first.first, memo[i+1][r].first.second), total);
                    ans=total;
                    memo[l][r] = curr;
                }
            }
        }
        // cout<<"<-("<<l<<", "<<r<<"): "<< memo[l][r].second <<"\n";
    }

    int matrixMultiplication(int n, int arr[])
    {
        pairs = vector<p>(n-1);
        memo = vector<vector<pp>>(n-1);
        for(int i=0;i<n-1;i++){
            p curr = make_pair(arr[i], arr[i+1]);
            pairs[i]=curr;
        }
        for(int i=0;i<n-1;i++){
            pair<pair<int,int>, int> dummy = {{-1,-1}, -1};
            vector<pp> p(n-1, dummy);
            memo[i]=p;
        }
        // cout<<pairs<<"\n";
        this->dp(0, pairs.size()-1);
        // cout<<memo<<endl;
        return memo[0][pairs.size()-1].second;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout << ob.matrixMultiplication(n, arr) <<"\n";
    }
    return 0;
}