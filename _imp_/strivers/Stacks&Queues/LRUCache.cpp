#include<bits/stdc++.h>
#include <iostream>
#include <ostream>
using namespace std;
class Node {
    public:
        int key, value;
        Node *next, *prev;
        Node(int k, int v) {
            key = k;
            value = v;
            next=nullptr;
            prev=nullptr;
        }
};

class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> umap;
    Node* tail=nullptr;
    Node* head=nullptr;

    LRUCache(int capacity) {
        cap = capacity;    
    }
    
    int get(int key) {
        if(umap.find(key)==umap.end()) return -1;
        Node* curr = umap[key];
        if(curr==head) {
            return curr->value;
        } else {
            if(curr==tail) {
                tail=tail->next;
                tail->prev = nullptr;
            } else {
                curr->next->prev = curr->prev;
                curr->prev->next = curr->next;    
            }

            curr->next = nullptr;
            head->next = curr;
            curr->prev = head;
            head=head->next;

            return curr->value;
        }
    }
    
    void put(int key, int value) {
        cout<<"put: "<<key<<" "<<value<<"\n";
        if(umap.find(key)!=umap.end()) {
            cout<<"existing key: "<<"\n";
            Node *curr = umap[key];
            curr->value = value;
            if(curr==head) {
                return;
            } else {
                if(curr==tail) {
                    tail=tail->next;
                    tail->prev=nullptr;
                } else {
                    curr->next->prev = curr->prev;
                    curr->prev->next = curr->next;                    
                }
                curr->next = nullptr;
                head->next = curr;
                curr->prev = head;
                head=curr;
            }
        } else {
            cout<<"non-existing key: "<<"\n";
            if(umap.size() == cap) {
                cout<<"deleting tail: "<<"\n";
                Node* tmp = tail;
                if(tail==head) {
                    tail=nullptr;
                    head=nullptr;
                } else {
                    tail=tail->next;
                    tail->prev = nullptr;
                    tmp->next=nullptr;
                }

                umap.erase(tmp->key);
                delete tmp;
            }

            Node* newNode = new Node(key, value);
            if(head==nullptr) {
                head=newNode;
                tail=newNode;
            } else {
                newNode->prev = head;
                head->next = newNode;
                head=head->next;
            }

            umap[key]=newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache lr(2);

    lr.put(1, 1);
    lr.put(2, 2);
    cout<<lr.get(1)<<endl;
    lr.put(3, 3);
    cout<<lr.get(2)<<endl;
    // lr.put(4, 4);
    // cout<<lr.get(1)<<endl;
    // cout<<lr.get(3)<<endl;
    // cout<<lr.get(4)<<endl;

    return 0;
}