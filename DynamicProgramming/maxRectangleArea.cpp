#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

class Solution{
  public:
    int maxRectangleInArray(int arr[], int n){
        vector<int> lm(n, -1);
        stack<int> s=stack<int>();
        
        //left Min
        s.push(0);
        for(int i=1;i<n;i++){
            while(!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            
            if(!s.empty())
                lm[i] = s.top();
            s.push(i);
        }
        
        //right Min
        s=stack<int>();
        s.push(n-1);
        int ans=(n-lm[n-1]-1)*arr[n-1];
        for(int i=n-2;i>=0;i--){
            while(!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            
            if(!s.empty()){
                ans = max(ans, (s.top()-lm[i]-1)*arr[i]);
            } else {
                ans = max(ans, (n-lm[i]-1)*arr[i]);
            }
            s.push(i);
        }
        
        return ans;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        int v[m];
        for(int i=0;i<m;i++)
            v[i]=M[0][i];
            
        int ans = maxRectangleInArray(v, m);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]==1)
                    v[j]+=1;
                else
                    v[j]=0;
            }
            ans = max(ans, maxRectangleInArray(v, m));
        }
        
        return ans;
    }
};