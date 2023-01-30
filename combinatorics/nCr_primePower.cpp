#include<bits/stdc++.h>
#include <cassert>
#include <tuple>
using namespace std;

class Prime_Power {
    public:
    #define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
    #define F first
    #define S second
    #define EB emplace_back
    #define MP make_pair
    #define all(o) (o).begin(), (o).end()
    #define mset(m, v) memset(m, v, sizeof(m))
    #define fr(i,n) for(lli i=0;i<(n); ++i)
    #define rep(i,a,b) for(lli i=a;i<=b;++i)
    #define per(i,a,b) for(lli i=a;i>=b; i--)
    #define remin(a,b) (a=min((a), (b)))
    #define remax(a,b) (a=max((a), (b)))
    #define sz(x) (lli)(x).size()
    #define endl '\n'
    
    typedef long long int lli;          typedef long double ld;
    typedef pair<lli,lli> ii;           typedef vector<lli> vi;
    typedef vector<ii> vii;             typedef vector<vi> graph;
    long long MOD = 1000000007;
    long double EPS = 1e-9;

    public:
    lli mul(lli a, lli b, lli MOD){
        return ((a%MOD)*(b%MOD))%MOD;
    }

    lli bin_pow(lli a, lli b, lli mod) {
        lli ans = 1LL;
        while(b) {
            if(b&1)
                ans = mul(ans, a, mod);
            a=mul(a,a, mod);
            b>>=1;
        }
        return ans;
    }

    lli inverse(lli a, lli b) {
        lli x=1, y=0;
        lli x1=0, y1=1, a1=a, b1=b;
        while(b1) {
            lli q = a1/b1;
            tie(x, x1) = make_tuple(x1, x-q*x1);
            tie(y, y1) = make_tuple(y1, y-q*y1);
            tie(a1,b1) = make_tuple(b1, a1 - q*b1);
        }
        // inverse of 'a' under b=(MOD)
        return x;
    }

    lli get_pow(lli n, lli prime) {
        lli ans = 0;
        while(n){
            n/=prime;
            ans+=n;
        }
        return ans;
    }

    lli fact_mod(lli n, lli prime, lli mod) {
        lli fact[mod+1];
        fact[1] = 1%mod;
        for(lli i=2;i<=mod;i++){
            if(i%prime)
                fact[i] = i * fact[i-1] % mod; // fact[i] has no factor of prime, so % mod != 0
            else
                fact[i] = fact[i-1];
        }

        lli ans = 1LL;
        while(n>1){
            ans = 1LL * ans * fact[n%mod] % mod;
            ans = 1LL * ans * bin_pow(fact[mod], n/mod, mod) % mod;
            n/=prime;
        }
        
        return ans;
    }

    /* 
        we already mod is p^a;
    */
    tuple<lli, lli> findPrimePower(lli primemod) {
        lli prime=-1, power=0;
        for(lli i=2;i<=primemod;i++) {
            if(primemod%i==0) {
                prime=i;
                while(primemod) {
                    primemod/=i;
                    power++;
                }
                break;
            }
        }
        return make_tuple(prime, power);
    }
    /**
        @param n: n in nCr
        @param r: r in nCr
        @param mod: modulo prime which is in form of p^a
        @param prime: (optional) p in p^a
        @param power: (optional) a in p^a
    */
    lli nCr(lli n, lli r, lli mod, lli prime = -1, lli power = -1) {

        if(prime==-1){
            tie(prime, power) = findPrimePower(mod);
            assert(prime==-1);
        }

        // get max power where p^x | n!/r!.(n-r)!
        lli t = get_pow(n, prime) - get_pow(r, prime) - get_pow(n-r, prime);
        
        if(t>=power)
            return 0;

        // you can pre-compute this if same prime & mod
        lli n_fact = fact_mod(n, prime, mod);
        lli r_fact = fact_mod(r, prime, mod);
        lli nr_fact = fact_mod(n-r, prime, mod);

        return n_fact * inverse(r_fact, mod) % mod * inverse(nr_fact, mod) % mod;
    }
};