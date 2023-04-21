#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  priority_queue<int> pq;
  int size;

  Solution(int k, vector<int> &nums) {
    size = k;
    pq = priority_queue<int>();
    for(int i=0;i<nums.size();i++) {
        add(nums[i]);
    }
  }

  int add(int val) {
    if(pq.size()==size) {
        if(-pq.top() >= val) 
            return -pq.top();
        pq.pop();
    }
    pq.push(-val);
    return -pq.top();
  }
};

int main() { return 0; }