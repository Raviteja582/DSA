#include <bits/stdc++.h>
using namespace std;

#define debarr(a, n)  cout << #a << " : "; for (int i = 0; i < n; i++) cerr << a[i] << " ";cerr << endl;
#define debmat(mat, row, col) cout << #mat << " :\n"; for (int i = 0; i < row; i++) { for (int j = 0; j < col; j++) cerr << mat[i][j] << " "; cerr << endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T> ostream &operator<<(ostream &os, const pair<S, T> &p) { return os << "(" << p.first << ", " << p.second << ")";}
template <class T> ostream &operator<<(ostream &os, const vector<T> &p) {os << "[ ";for (const auto &it : p)os << it << " ";return os << "]"<<endl;}
template <class T> ostream &operator<<(ostream &os, const unordered_set<T> &p) {os << "[ ";for (const auto &it : p)os << it << " ";return os << "]" <<endl;}
template <class S, class T> ostream &operator<<(ostream &os, const unordered_map<S, T> &p) {os << "[ ";for (const auto &it : p)os << it << " ";return os << "]" << endl;}
template <class T> ostream &operator<<(ostream &os, const set<T> &p) {os << "[ ";for (const auto &it : p)os << it << " ";return os << "]" << endl;}
template <class T> ostream &operator<<(ostream &os, const multiset<T> &p) {os << "[ ";for (const auto &it : p)os << it << " ";return os << "]" << endl;}
template <class S, class T> ostream &operator<<(ostream &os, const map<S, T> &p) {os << "[ ";for (const auto &it : p)os << it << " ";return os << "]" << endl;}
template <class T> void dbs(const string &str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(',');cerr << str.substr(0, idx) << " : " << t << ",";dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "[";for (T i = a; i != b; ++i) {if (i != a)cerr << ", ";cerr << *i;}cerr << "]\n";}

long long pow_mod(long long a, long long b, long long m) {
  a = (a % m + m) % m;
  long long r = 1;
  while (b) {
    if (b & 1) {
      r = r * a % m;
    }
    a = a * a % m;
    b /= 2;
  }
  return r;
}

long long extended_euclid(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  long long x1, y1;
  long long d = extended_euclid(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

long long inverse(long long a, long long m) {
  long long x, y;
  long long g = extended_euclid(a, m, x, y);
  if (g != 1) {
    return -1;
  }
  return (x % m + m) % m;
}

struct Binomial_Coefficients {
  int n, MOD;
  vector<long long> fac, ifac, inv;
  Binomial_Coefficients() {}
  Binomial_Coefficients(int n, int MOD) : n(n), MOD(MOD), fac(n), ifac(n), inv(n) {
    fac[0] = ifac[0] = 1;
    inv[1] = 1;
    for (int i = 2; i < n; ++i) {
      inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    }
    for (int i = 1; i < n; ++i) {
      fac[i] = fac[i - 1] * i % MOD;
      ifac[i] = ifac[i - 1] * inv[i] % MOD;
    }
  }
  void init(int _n, int _MOD) {
    n = _n;
    MOD = _MOD;
    fac = vector<long long>(n);
    ifac = vector<long long>(n);
    inv = vector<long long>(n);
    fac[0] = ifac[0] = 1;
    inv[1] = 1;
    for (int i = 2; i < n; ++i) {
      inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    }
    for (int i = 1; i < n; ++i) {
      fac[i] = fac[i - 1] * i % MOD;
      ifac[i] = ifac[i - 1] * inv[i] % MOD;
    }
  }
  int com(int a, int b) {
    if (a < 0 || b < 0 || a < b) {
      return 0;
    }
    return fac[a] * ifac[b] % MOD * ifac[a - b] % MOD;
  }
};

Binomial_Coefficients binom;

long long lucas(long long a, long long b, int MOD) {
  if (a < 0 || b < 0 || a < b) {
    return 0;
  }
  if (a < MOD) {
    return binom.com(a, b);
  }
  return lucas(a / MOD, b / MOD, MOD) * lucas(a % MOD, b % MOD, MOD) % MOD;
}

long long get_c(long long n, int p) {
  long long ans = 0;
  while (n) {
    n /= p;
    ans += n;
  }
  return ans;
}

int facmod(long long n, int p, int mod) {
  vector<int> f(mod + 1);
  f[0] = 1 % mod;
  for (int i = 1; i <= mod; i++) {
    if (i % p) f[i] = 1LL * f[i - 1] * i % mod;
    else f[i] = f[i - 1];
  }

  int ans = 1 % mod;
  while (n > 1) {
    ans = 1LL * ans * f[n % mod] % mod;
    ans = 1LL * ans * pow_mod(f[mod], n / mod, mod) % mod;
    n /= p;
  }
  return ans; 
}

long long nCr(long long a, long long b, int mod, int power) {
  // a! / (b! * (a - b)!) % (mod ^ power)
  if (a < 0 || b < 0 || a < b) {
    return 0;
  }
  long long t = get_c(a, mod) - get_c(b, mod) - get_c(a - b, mod);
  if (t >= power) {
    return 0;
  }
  int Mod = pow(mod, power);
  // cout << a << " " << b << " " << mod << " " << power << " " << facmod(a, mod, Mod) << " " << facmod(b, mod, Mod) << " " << facmod(a - b, mod, Mod) << "\n";
  return facmod(a, mod, Mod) * inverse(facmod(b, mod, Mod), Mod) % Mod * inverse(facmod(a - b, mod, Mod), Mod) % Mod * pow_mod(mod, t, Mod) % Mod;
}

pair<long long, long long> CRT(long long a1, long long n1, long long a2, long long n2) {
  long long x, y;
  long long d = extended_euclid(n1, n2, x, y);
  pr(d,x,y);
  if ((a2 - a1) % d) {
    return make_pair(0, -1);
  }
  long long ans = (a1 + n1 * ((x * (a2 - a1) / d) % (n2 / d))) % (n2 / d * n1);
  if (ans < 0) {
    ans += (n2 / d * n1);
  }
  return make_pair(ans, n2 / d * n1);
}

const int NAXM = 1000000;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> lf(NAXM + 5);
  
  //making the smallest prime in their factorization.
  for (int i = 2; i * i <= NAXM; ++i) {
    if (!lf[i]) {
      for (int j = i * i; j <= NAXM; j += i) {
        lf[j] = i;
      }
    }
  }

  // marking primes numbers to itself.
  for (int i = 2; i <= NAXM; ++i) {
    if (!lf[i]) {
      lf[i] = i;
    }
  }

  int tt;
  cin >> tt;
  while (tt--) {
    long long n, k; int MOD;
    cin >> n >> k >> MOD;
    if (lf[MOD] == MOD) { // Sub3 -- Lucas
      binom.init(MOD, MOD);
      long long ans = n / k + (n % k != 0);
      long long x = (k - (n % k)) % k;
      long long ways = lucas(x + ans - 1, ans - 1, MOD);
      cout << ans << " " << ways << "\n";
    } else { // Sub4 -- CRT
      long long ans = n / k + (n % k != 0);
      long long X = (k - (n % k)) % k;
      // cout << X << "\n";
      int Mod = MOD;
      vector<long long> rem, pp;
      while (Mod > 1) {
        int p = lf[Mod];
        int x = 0;
        int mod = 1;
        while (Mod % p == 0) {
          Mod /= p;
          ++x;
          mod *= p;
        }
        pp.push_back(mod);
        rem.push_back(nCr(X + ans - 1, ans - 1, p, x));
        // cout << mod << " " << nCr(X + ans - 1, ans - 1, p, x) << "\n";
      }
      debarr(pp, pp.size());
      debarr(rem, rem.size());
      if (rem.size()) {
        long long ways = rem[0];
        Mod = pp[0];
        for (int i = 1; i < (int) (rem.size()); ++i) {
          pair<long long, long long> f = CRT(ways, Mod, rem[i], pp[i]);
          pr(f);
          ways = f.first;
          Mod = f.second;
          assert(Mod != -1);
        }
        cout << ans << " " << ways << "\n";
      } else {
        cout << ans << " " << 1 << "\n";
      }
    }
  }
  return 0;
}