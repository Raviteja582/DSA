#include<bits/stdc++.h>
#include "ExtendedEuclid.cpp"
using namespace std;

// inverse using extended euclid algorithm
long long inverse(long long a, long long m) {
  long long x, y;
  long long g = extended_euclid(a, m, x, y);
  if (g != 1) {
    return -1;
  }
  return (x % m + m) % m;
}

// p = MOD-2
// fermat's little theorem
lli binpow(lli b, lli p, lli mod) {
    lli ans = 1;
    b %= mod;
    for (; p; p >>= 1) {
        if (p & 1)
            ans = ans * b % mod;
        b = b * b % mod;
    }
    return ans;
}
