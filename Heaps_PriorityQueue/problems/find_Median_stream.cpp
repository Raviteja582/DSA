#include<bits/stdc++.h>
#include <complex>
#include <queue>
#include <valarray>
using namespace std;

class Solution {
    public:
    priority_queue<int> maxH;
    priority_queue<int> minH;

    Solution() {
        minH = priority_queue<int>();
        maxH = priority_queue<int>();
    }
    
    void addNum(int num) {
        maxH.push(num);
        // first consider the size
        if( abs((int)maxH.size()-(int)minH.size()) > 1) {
            // getting top element...
            int top = maxH.top(); maxH.pop();
            // pushing into min Heap
            minH.push(-top);
        }
        
        // second consider the median      
        if(!minH.empty()) {
            int maxTop = maxH.top();
            int minTop = -minH.top();
            if(maxTop > minTop) {
                maxH.pop();
                minH.pop();
                minH.push(-maxTop);
                maxH.push(minTop);
            }
        }
    }
    
    double findMedian() {
        int maxS = maxH.size();
        int minS = minH.size();

        if((maxS+minS)%2) { // odd
            return (double)maxH.top();
        }  else { // even
            double med = ((double)(-minH.top()) + (double)maxH.top())/(double )2.0;
            return med;
        }
    }
};

int main() {

    return 0;
}