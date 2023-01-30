#include <bits/stdc++.h>
#include <bitset>
using namespace std;

#define M 32

int main(){

    /*
        If you declare like this, then you have array 
        of 32 0's indexing from right.
    */ 
    bitset<M> b2;
    cout<<b2<<"\n";
    /*
        Dynamic Value.
        load the bitset array with 32 bit's size of x
    */
    int x;cin>>x;
    bitset<M> b1(x);
    cout<<b1<<"\n";
    // count set bits
    cout<<b1.count()<<endl;
    // see all bits are set 
    cout<<b1.all()<<endl;
    // see atleast one bit is set
    cout<<b1.any()<<endl;
    // set all bits to 1, modify the original bitset.
    cout<<b1.set()<<endl;
    // return to binary string.
    cout<<b1.to_string()<<endl;


    // bitwise operations:
    b1 &= b2;
    b1 |=b2;
    b1^=b2;

    cout<< ~b1 <<endl;

    cout << (b1 & b2) <<endl;
    cout<< (b1 | b2) <<endl;
    cout<< ( b1 ^ b2 ) << endl;
    return 0;
}