// Construction of segment trees.

#include <bits/stdc++.h>
using namespace std;


// Structure
/*
/                                    index=1
                        index=2(2*i)        index=3(2*i+1)
                    index=4     index=5  index=6        index=7  
/
/
/
*/

class Solution {
    public:
        // if size of the given array is N, then segment tree should be of atleast 4*N;
        int segment[400400];

        void buildSegmentTree(int index, int l, int r, int arr[]){
            // leaf node condition...
            if(l==r){
                segment[index]=arr[l];
                return;
            }

            int mid=(l+r)/2;
            // build segment for left node from l to half range.
            buildSegmentTree(2*index, l, mid, arr);

            // build segment for right node from half range + 1 to r.
            buildSegmentTree(2*index+1, mid+1, r, arr);

            // add the sum from two half ranges to have complete sum from l to r.
            segment[index] = segment[2*index] + segment[2*index+1];
        }

        void updateSegmentTree(int index, int l, int r, int pos, int val){
            // check pos is outside the range.
            if(pos<l || pos>r) return;

            // pos is either l or r
            if(l==r){
                // so update current leaf node.
                segment[index] = val;
                return;
            }

            // else pos is in the range, so check in left & right node.
            int mid=(l+r);
            updateSegmentTree(2*index, l, r, pos, val);
            updateSegmentTree(2*index+1, l, r, pos, val);

            //update current index:
            segment[index]=segment[2*index] + segment[2*index+1];
        }

        int query(int index, int l, int r, int lq, int rq){
            // check both ranges are disjoint...
            if(lq>r || l>rq)
                return 0;
            // if current range is entirely in given range, then add the current node sum
            if(lq<=l && r<=rq)
                return segment[index];
            
            int mid = (l+r)/2;
            
            // add sum of left node and right node
            return query(2*index, l, mid, lq, rq) + query(2*index+1, mid+1, r, lq, rq);
        }
};

int main(){

    Solution sb;

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    sb.buildSegmentTree(1, 0, n-1, arr);

    int q;
    cin>>q;

    for(int i=0;i<q;i++){
        int choice;
        cin>>choice;
        if(choice==1){
            int pos, val;
            cin>>pos>>val;
            sb.updateSegmentTree(1, 0, n-1, pos, val);
        } else {
            int l, r;
            cin>> l >> r;
            cout<<sb.query(1, 0, n-1, l, r)<<'\n';
        }
    }

    return 0;
}