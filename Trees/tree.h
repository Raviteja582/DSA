#include<bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node *left, *right;

    node() {
        val=-1,
        left=nullptr;
        right=nullptr;
    }

    node(int data) {
        val=data;
        left=nullptr;
        right=nullptr;
    }
};