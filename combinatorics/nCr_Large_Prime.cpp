#include<bits/stdc++.h>
using namespace std;


/**
    Observations:
        1. Used to calculate nCr mod large prime.
        2. n<=10^5, r<=10^5 and mod = 10^9+7
    Precomputation:
        1. we can pre-compute fact[i] for [1, n].
        2. We cannot pre-compute inverse factorials, because
            i. inv[i] should compute over range [1 m-1]
            ii. here m = 1000000007, so we cannot create a range of 10^9+7 array
            iii. and, inv[fact[r]] and inv[fact[n-r]] cannot be accessed due to fact[i]<m
*/
class Solution {
    /*  
        As mod is a prime, it is co-prime to all (n!), we can use directly
        1. Calculate all factorials precomputed till mod
    */
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
    
    #define MAX MOD
    vi fact;

    lli inverse_power_modulo(lli a){
        lli ans = 1, b = MOD-2;
        while(b) {
            if(b&1)
                ans=mul(ans, a);
            a=mul(a,a);
            b>>=1;
        }
        return ans;
    }
    
    lli gcd(lli a, lli b, lli& x, lli& y) {
        x = 1, y = 0;
        lli x1 = 0, y1 = 1, a1 = a, b1 = b;
        while (b1) {
            lli q = a1 / b1;
            tie(x, x1) = make_tuple(x1, x - q * x1);
            tie(y, y1) = make_tuple(y1, y - q * y1);
            tie(a1, b1) = make_tuple(b1, a1 - q * b1);
        }
        return a1;
    }

    lli extended_euclid_modulo(lli a){
        lli m0=MOD, m=MOD;
        lli x, y;
        gcd(a, MOD, x, y);
        return x;
    }

    lli mul(lli a, lli b){
        return ((a%MOD)*(b%MOD))%MOD;
    }

    void preCompute(int n){
        fact[0]=1LL;
        for(lli i=1;i<=n;i++){
            fact[i]=fact[i-1]*i % MOD;
        }
    }
    
    int nCr(long long n, long long r) {
        fact.assign(n+1, 1);
        preCompute(n);
        n=n%MOD;
        r=r%MOD;
        cout<<fact[n]<<" "<<fact[r]<<" "<<fact[n-r]<<"\n";
        lli ans = mul(
                    fact[n], 
                    mul(
                        extended_euclid_modulo(fact[r]), 
                        extended_euclid_modulo(fact[n-r])
                        )
                    );
        /*lli ans = mul(
                    fact[n], 
                    mul(
                        inverse_power_modulo(fact[r]), 
                        inverse_power_modulo(fact[n-r])
                        )
                    );*/
        return ans;
    }
};

int main() {
    FAST;
    long long int n=384, r =487;
    Solution sb;
    cout<<sb.nCr(n, r);
    return 0;
}