// User function Template for C++
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    #define p 1000003   
    
    vector<int> fact=vector<int>(16);
    Solution(){
        cal();    
    }
    
    void cal(){
        fact[0]=1;
        for(int i=1;i<16;i++)
            fact[i]=(fact[i-1]*i)%p;
    }
    
    int calculatePos(char c){
        int pos=(int)c;
        if(pos>=97)
            pos=26+(pos-97);
        else
            pos-=65;
        return pos;
    }
    
    int calculateLetters(vector<int> &v,char c){
        int count=0;
        int pos = calculatePos(c);
        for(int i=0;i<pos;i++){
            if(v[i] && v[i]!=2)
                count+=1;
        }
        v[pos]=2;
        return count;
    }
    
    int rank(string S){
        int ans = 0;
        vector<int> v(52,0);
        for(int i=0;i<S.size();i++){
            int pos=calculatePos(S[i]);
            if(v[pos])
                return 0;
            v[pos]=1;
        }
        
        for(int i=0;i<S.size()-1;i++){
            int r = calculateLetters(v,S[i]);
            ans += (r*fact[S.size()-(i+1)]%p)%p;
        }
        return (ans+1)%p;
    }
};