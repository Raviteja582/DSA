#include<bits/stdc++.h>
#include <cstdio>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
#include "../../tree.h"
using namespace std;


#define debarr(a, n)  cout << #a << " : "; for (int i = 0; i < n; i++) cerr << a[i] << " ";cerr << endl;
#define debmat(mat, row, col) cout << #mat << " :\n"; for (int i = 0; i < row; i++) { for (int j = 0; j < col; j++) cerr << mat[i][j] << " "; cerr << endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T> ostream &operator<<(ostream &os, const pair<S, T> &p) { return os << "(" << p.first << ", " << p.second << ")";}
template <class T> ostream &operator<<(ostream &os, const vector<T> &p) {os << "[ ";for (const auto &it : p)os << it << " ";return os << "]"<<endl;}
template <class T> ostream &operator<<(ostream &os, const unordered_set<T> &p) {os << "[ ";for (const auto &it : p)os << it << " ";return os << "]" <<endl;}
template <class S, class T> ostream &operator<<(ostream &os, const unordered_map<S, T> &p) {os << "[ ";for (const auto &it : p)os << it << " ";return os << "]" << endl;}
template <class T> ostream &operator<<(ostream &os, const set<T> &p) {os << "[ ";for (const auto &it : p)os << it << " ";return os << "]" << endl;}
template <class T> ostream &operator<<(ostream &os, const multiset<T> &p) {os << "[ ";for (const auto &it : p)os << it << " ";return os << "]" << endl;}
template <class S, class T> ostream &operator<<(ostream &os, const map<S, T> &p) {os << "[ ";for (const auto &it : p)os << it << " ";return os << "]" << endl;}
template <class T> void dbs(const string &str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(',');cerr << str.substr(0, idx) << " : " << t << ",";dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "[";for (T i = a; i != b; ++i) {if (i != a)cerr << ", ";cerr << *i;}cerr << "]\n";}

class Solution {
    private:
    char delimit = '#';
    public:
    string serialize(node* root) {
        string ans="";
        queue<node*> q;
        if(!root) return ans;
        q.push(root);
        while(!q.empty()) {
            int currSize = q.size();
            for(int i=0;i<currSize;i++) {
                node *tmp = q.front(); q.pop();

                string strNode;
                if(tmp==nullptr) {
                    strNode = "N";
                    ans.append(strNode);
                    ans.push_back(delimit);
                    continue;
                }

                strNode = to_string(tmp->val);
                ans.append(strNode);
                ans.push_back(delimit);

                if(tmp->left)
                    q.push(tmp->left);
                else 
                    q.push(nullptr);

                if(tmp->right)
                    q.push(tmp->right);
                else
                    q.push(nullptr);
            }
        }
        ans.pop_back();
        return ans;
    }

    vector<string> getNodes(string data, char delimit) {
        vector<string> ans;
        string intermediate;
        
        stringstream cmp(data);

        while(getline(cmp, intermediate, delimit)) {
            ans.push_back(intermediate);
        }

        return ans;
    }

    string getNode(vector<string> &nodes,int &currInd) {
        string node;
        if(currInd<nodes.size()) 
            node =  nodes[currInd];
        else {
            node = "";
        }
        currInd++;
        return node;
    }

    void addNode(node **root, vector<string> &nodes, int &currInd, int direction) {
        string token = getNode(nodes, currInd);
        node *newNode;
        
        if(token.compare("")==0)
            return;

        if(token.compare("N")==0) {
            newNode = nullptr;
        } else {
            pr(currInd, token);
            newNode = new node(stoi(token));
        }
        if(direction) { // right
            (*root)->right = newNode;
        }
        else { // left
            (*root)->left = newNode;
        }
    }

    // Decodes your encoded data to tree.
    node* deserialize(string data) {
        if(data.compare("")==0) return nullptr;
        vector<string> nodes = getNodes(data, delimit);
        pr(nodes, nodes.size());
        int currInd = 0;
        node* root = new node(stoi(nodes[currInd++]));
        queue<node*> q;
        q.push(root);

        while(!q.empty()) {
            node* tmp = q.front(); q.pop();
            
            if(currInd>=nodes.size())
                break;

            addNode(&tmp, nodes, currInd, 0);
            if(tmp->left){
                q.push(tmp->left);
            }
            addNode(&tmp, nodes, currInd, 1);
            if(tmp->right) {
                q.push(tmp->right);
            }
        }

        return root;
    }


    string createTree(string str) {
        string nodes = "";
        vector<string> arr = getNodes(str, ',');
        for(auto x:arr) {
            if(x.compare("null")==0)
                nodes.append("N#");
            else {
                nodes.append(x);
                nodes.append("#");
            }
        }
        nodes.pop_back();
        return nodes;
    }
};

int main() {
    Solution sb;
    string str;
    getline(cin, str);

    string nodes = sb.createTree(str);
    node* root = sb.deserialize(nodes);

    string ser = sb.serialize(root);

    pr(ser);
    return 0;
}