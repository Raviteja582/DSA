// Link: https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1?page=1&status[]=unsolved&curated[]=4&sortBy=submissions

#include <bits/stdc++.h>
#include <ios>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution{
    #define MOD 1003
    public:

    int mul(int a, int b){
        return ((a%MOD)*(b%MOD))%MOD;
    }

    int add(int a, int b){
        return ((a%MOD)+(b%MOD))%MOD;
    }


    pair<int,int> findBoolean(const pair<int, int> &a, const pair<int,int> &b, char c){
        int nt = 0, nf = 0;
        
        int t1=a.first, t2=b.first;
        int f1=a.second, f2=b.second;

        if(c=='&'){
            nt = mul(t1, t2);
            nf = add( mul(t1, f2), add( mul(t2, f1), mul(f1, f2) ) );
        } else if(c=='|'){
            nt = add( mul(t1, f2), add( mul(t2, f1), mul(t1, t2) ) );
            nf = mul(f1, f2);
        } else {
            nt = add(mul(t1, f2), mul(t2, f1));
            nf = add( mul( t1, t2), mul(f1, f2));
        }
        return {nt, nf};
    }


    int findTrueExpression(string s){
        
        int n=s.size();
        if((n&1) == 0)
            return 0;
        
        vector<vector<pair<int,int>>> ans(
                n/2+1, 
                vector<pair<int,int>>( 
                    n/2+1, 
                    make_pair(0, 0)
                )
            );
        
        // making diagonal values as true or false;
        for(int i=0;i<n;i+=2){
            int ind=i/2;
            if(s[i]=='T')
                ans[ind][ind] = make_pair(1, 0);
            else
                ans[ind][ind] = make_pair(0, 1);    
        }

        for(int i=2;i<n;i+=2){
            for(int l=0,r=i;r<n;l+=2, r+=2){
                // 0 based index
                int x=l/2,y=r/2;
                ans[x][y] = make_pair(0, 0);
                for(int j=l;j<r;j+=2){
                    pair<int,int> p = findBoolean(ans[x][j/2], ans[(j/2)+1][y], s[j+1]);
                    ans[x][y].first=add(ans[x][y].first,p.first);
                    ans[x][y].second=add(ans[x][y].second,p.second);
                }
            }
        }

        // for(int i=0;i<=(n/2);i++){
        //     for(int j=0;j<=(n/2);j++)
        //         cout<<"("<<ans[i][j].first<<","<<ans[i][j].second<<')'<<" ";
        //     cout<<"\n";
        // }
        // cout<<"\n";

        return ans[0][n/2].first;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin,s);

    Solution ob;
    cout<<ob.findTrueExpression(s);
    return 0;
}