#include<bits/stdc++.h>
using namespace std;

class MinStack {
    public:
    #define ll long long
    stack<ll> st;
    ll mini;
    MinStack() {
     st=stack<ll>();
     mini=INT_MAX;
    }
    
    void push(int val) {
        ll v=(ll)val;
        if(st.empty()){
            st.push(v);
            mini=v;       
        } else {
            if(v<mini) {
                st.push(2*v*1LL - mini);
                mini=v;
            } else {
                st.push(v);
            }
        }
    }
    
    void pop() {
        ll ele = st.top();
        st.pop();
        if(ele < mini ) {
            mini = 2*mini - ele;
        }
        return; 
    }
    
    int top() {
        ll ele = st.top();
        if(ele<mini) return (int)mini;
        return (int)ele;
    }
    
    int getMin() {
        return mini;    
    }
};

int main() {

    return 0;
}