#include <algorithm>
#include<bits/stdc++.h>
#include <climits>
#include <unordered_set>
using namespace std;

class Solution {
    public:
    int minCost(int n, vector<int>& cuts) {
        
        return 0;   
    }
};

int main() {
    set<int> ss;
    ss.insert({2,4,5,9,1});
    auto ele = lower_bound(ss.begin(), ss.end(), 3);
    if(ele==ss.end())
        cout<<"No element";
    else
        cout<<"element: "<<*ele;
    return 0;
}