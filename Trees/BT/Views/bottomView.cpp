#include<bits/stdc++.h>
#include <unordered_map>
#include "../../tree.h"
using namespace std;

class Solution {
    public:
    /*
        topView is also the same approach,
        but instead of assiging mmap[c.second]=c.first->val,
        we check whether the key exists, if yes don't update the answer, else add the key.
    */
    vector <int> bottomView(node *root) {
        if(root==nullptr) return vector<int>();
        unordered_map<int, int> mmap;
        queue<pair<node*, int>> q;
        q.push({root, 0});
        mmap[0]=root->val;
        int minV=INT_MAX, maxV=INT_MIN;
        
        while(!q.empty()) {
            int cz=q.size();
            for(int i=0;i<cz;i++) {
                pair<node*, int> c=q.front();q.pop();
                mmap[c.second]=c.first->val;
                
                minV=min(minV, c.second);
                maxV=max(maxV, c.second);
                
                if(c.first->left) {
                    q.push({c.first->left, c.second-1});
                } 
                if(c.first->right) {
                    q.push({c.first->right, c.second+1});
                }
            }
        }
        
        vector<int> ans;
        for(int i=minV;i<=maxV;i++) {
            if(mmap.find(i)!=mmap.end()){
                ans.push_back(mmap[i]);
            }
        }
        return ans;
    }

};

int main() {

    return 0;
}