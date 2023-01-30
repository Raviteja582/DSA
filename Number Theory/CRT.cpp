#include<bits/stdc++.h>
#include <vector>
#include "inverseModP.cpp"
using namespace std;
#define ll long long


// using of Guass algorithm...
/**
  @param a: vector of remainders a[i], when x%m[i];
  @param m: vector of m[i], where pairwise m[i], m[j] are co-prime.
  link: https://trans4mind.com/personal_development/mathematics/numberTheory/chineseRemainderTheoremFormula2.htm
*/
long long CRT(vector<long long> &a, vector<long long> &m) {
	long long M = 1, ret = 0; 
	for(long long num : m) M *= num;
	for(int i=0; i<a.size(); i++) {
		long long x = M / m[i];
		long long y = inverse(x, m[i]);
		ret = (ret + (a[i] * x) % M * y) % M;
	}
  return ret;
}


// this is run with for loop with all rem[], mods:[]
// check PDF of crt_eculid.pdf
pair<ll, ll> CRT(ll a1, ll m1, ll a2, ll m2) {
  ll p, q;
  ll g = extended_euclid(m1, m2, p, q);
  if (a1 % g != a2 % g) return make_pair(0, -1);
  ll m = m1 / g * m2;
  p = (p % m + m) % m;
  q = (q % m + m) % m;
  return make_pair((p * a2 % m * (m1 / g) % m + q * a1 % m * (m2 / g) % m) %  m, m);
}


// easy crt
// should run with for loop
pair<long long, long long> Easy_CRT(long long a1, long long n1, long long a2, long long n2) {
  long long x, y;
  long long d = extended_euclid(n1, n2, x, y);
  pr(d,x,y);
  if ((a2 - a1) % d) {
    return make_pair(0, -1);
  }
  // easy crt formula: https://math.stackexchange.com/questions/20223/solving-2-congruences-by-crt-chinese-remainder-theorem/20259#20259
  long long ans = (a1 + n1 * ((x * (a2 - a1) / d) % (n2 / d))) % (n2 / d * n1);
  if (ans < 0) {
    ans += (n2 / d * n1);
  }
  return make_pair(ans, n2 / d * n1);
}

// helper function for CRT using
/**
  1. Easy CRT
  2. extended_euclid based CRT
*/
long long helper(const vector<long long> &a,const vector<long long> &m) {
  long long rem = a[0];
  long long mod = m[1];
  for(int i=1;i<a.size();i++){
    pair<long long, long long> intermediate_nCr;
    intermediate_nCr = Easy_CRT(rem, mod, a[i], m[i]);
    rem = intermediate_nCr.first;
    mod = intermediate_nCr.second;
    /**
      intermediate_nCr = CRT(rem, mod, a[i], m[i]);
      rem = intermediate_nCr.first;
      mod = intermediate_nCr.second;
    */
  }
  return rem;
}


// Garner's implementation O(n^2)