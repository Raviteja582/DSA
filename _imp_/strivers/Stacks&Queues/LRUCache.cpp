#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

class LRUCache {
    public:
    struct node {
        int  key, val;
        node *left, *right;
        node(): key(-1), val(-1), left(nullptr), right(nullptr) {};
        node(int k, int v): key(k), val(v), left(nullptr), right(nullptr){};  
    };
    unordered_map<int,node*> nm;
    node *head, *tail;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
        nm=unordered_map<int, node*>();
        head=nullptr, tail=nullptr;
    }
    
    int get(int key) {
        
    }

    void updateToEnd(node *tmp) {

    }
    
    void put(int key, int value) {
        if(nm.find(key)!=nm.end()) {
            node *tmp = nm[key];
            tmp->val = value;
            updateToEnd(tmp);
        }
        
        node *tmp = new node(key, value);
        if(head==nullptr) {
            nm[key]=tmp;
            head=tmp;tail=tmp;
        } else if(nm.size() == cap) { 
            node *st=head;
            head=head->right;
            if(head!=nullptr) {
                head->left = nullptr;
                st->right=nullptr;
                nm.erase(st->key);
            }   
            delete st;
        }
    }
};

int main() {

    return 0;
}