#include<bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<int, Node*> nm;

    Node* createNode(Node* node) {
        if(node==nullptr)
            return nullptr;

        if(nm.find(node->val)!=nm.end())
            return nm[node->val];
        else {
            Node* newNode = new Node(node->val);
            nm[newNode->val]=newNode;

            for(auto nn: node->neighbors) {
                newNode->neighbors.push_back(createNode(nn));
            }
            return newNode;
        }
    }

    Node* cloneGraph(Node* node) {
        if(node==nullptr)
            return nullptr;
        return createNode(node);
    }
};

void printGraph(Node* node, unordered_set<int> &s) {
    if(node==nullptr || s.find(node->val) != s.end())
        return;
    
    s.insert(node->val);
    cout<<node->val<<" -> ";
    for(Node* nn: node->neighbors) {
        printGraph(nn, s);
    }
}

int main() {
    int n;
    cin>>n;
    unordered_map<int, Node*> nn;
    for(int i=1;i<=n;i++) {
        nn[i]=new Node(i);
    }

    for(int i=1;i<=n;i++) {
        int a,b;
        cin>>a>>b;
        nn[i]->neighbors.push_back(nn[a]);
        nn[i]->neighbors.push_back(nn[b]);
    }

    Solution sb;
    Node* newGraph = sb.cloneGraph(nn[1]);
    unordered_set<int> ss;
    cout<<"Original: ";
    printGraph(nn[1], ss);
    ss.clear();
    cout<<"\ncloned: ";
    printGraph(newGraph, ss);
    return 0;
}