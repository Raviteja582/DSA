#include<bits/stdc++.h>
#include <vector>
#include "nCr_primePower.cpp"
#include "../Number Theory/CRT.cpp"
using namespace std;

// n<=10^18, r<=10^18, arbitary number<=10^6
class Arbitary_PrimePower: Prime_Power {
    public: 
    lli nCr_PrimePower(lli n, lli r, lli mod) {
        vector<lli> rem, pp;
        for(int i=2;i*i<=mod; i++) {
            if(mod%i==0){
                lli power=0, prime_mod=1;
                while(mod%i==0){
                    mod/=i;
                    power++;
                    prime_mod*=i;
                }
                pp.push_back(prime_mod);
                rem.push_back(nCr(n, r, prime_mod, i, power));
            }
        }

        lli ans = CRT(rem, pp);
        return ans;
    }
};