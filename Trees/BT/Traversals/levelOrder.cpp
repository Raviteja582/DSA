#include<bits/stdc++.h>
#include <queue>
#include <vector>
#include "../../tree.h"
using namespace std;

class Solution {
    public:

    /*
        using TUF way: for Loop
    */
    vector<vector<int>> levelOrder_1(node *root) {

        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue<node*> q;
        q.push(root);
        while(!q.empty()) {
            int cz=q.size();
            ans.push_back(vector<int>(q.size(),0));
            for(int i=0;i<cz;i++) {
                auto it = q.front(); q.pop();
                ans[ans.size()-1][i]=it->val;
                if(it->left)
                    q.push(it->left);
                if(it->right)
                    q.push(it->right);
            }
        }
        return ans;
    }

    /*
        using NULL character for each level
    */
    vector<vector<int>> levelOrder_2(node *root) {
        vector<vector<int>> ans;
        vector<int> a;
        if(root==nullptr) return ans;
        queue<node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            auto it = q.front(); q.pop();
            if(it!=nullptr) {
                a.push_back(it->val);
                if(it->left)
                    q.push(it->left);
                if(it->right)
                    q.push(it->right);
            } else {
                ans.push_back(a);
                a.erase(a.begin(),a.end());
                if(!q.empty())
                    q.push(NULL);
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}