#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstddef>
#include <cstring>
#include <vector>
using namespace std;

#define FAST                                                                   \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define F first
#define S second
#define EB emplace_back
#define MP make_pair
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define fr(i, n) for (lli i = 0; i < (n); ++i)
#define rep(i, a, b) for (lli i = a; i <= b; ++i)
#define per(i, a, b) for (lli i = a; i >= b; i--)
#define remin(a, b) (a = min((a), (b)))
#define remax(a, b) (a = max((a), (b)))
#define sz(x) (lli)(x).size()
#define endl '\n'

typedef long long int lli;
typedef long double ld;
typedef pair<lli, lli> ii;
typedef vector<lli> vi;
typedef vector<ii> vii;
typedef vector<vi> graph;
long long MOD = 1000000007;
long double EPS = 1e-9;

#define debarr(a, n)                                                           \
  cout << #a << " : ";                                                         \
  for (int i = 0; i < n; i++)                                                  \
    cerr << a[i] << " ";                                                       \
  cerr << endl;
#define debmat(mat, row, col)                                                  \
  cout << #mat << " :\n";                                                      \
  for (int i = 0; i < row; i++) {                                              \
    for (int j = 0; j < col; j++)                                              \
      cerr << mat[i][j] << " ";                                                \
    cerr << endl;                                                              \
  }
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)

template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T> ostream &operator<<(ostream &os, const vector<T> &p) {
  os << "[ ";
  for (const auto &it : p)
    os << it << " ";
  return os << "]" << endl;
}
template <class T> ostream &operator<<(ostream &os, const unordered_set<T> &p) {
  os << "[ ";
  for (const auto &it : p)
    os << it << " ";
  return os << "]" << endl;
}
template <class S, class T>
ostream &operator<<(ostream &os, const unordered_map<S, T> &p) {
  os << "[ ";
  for (const auto &it : p)
    os << it << " ";
  return os << "]" << endl;
}
template <class T> ostream &operator<<(ostream &os, const set<T> &p) {
  os << "[ ";
  for (const auto &it : p)
    os << it << " ";
  return os << "]" << endl;
}
template <class T> ostream &operator<<(ostream &os, const multiset<T> &p) {
  os << "[ ";
  for (const auto &it : p)
    os << it << " ";
  return os << "]" << endl;
}
template <class S, class T>
ostream &operator<<(ostream &os, const map<S, T> &p) {
  os << "[ ";
  for (const auto &it : p)
    os << it << " ";
  return os << "]" << endl;
}
template <class T> void dbs(string str, T t) {
  cerr << str << " : " << t << "\n";
}
template <class T, class... S> void dbs(const string &str, T t, S... s) {
  int idx = str.find(',');
  cerr << str.substr(0, idx) << " : " << t << ",";
  dbs(str.substr(idx + 1), s...);
}
template <class T> void prc(T a, T b) {
  cerr << "[";
  for (T i = a; i != b; ++i) {
    if (i != a)
      cerr << ", ";
    cerr << *i;
  }
  cerr << "]\n";
}
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

void convertToArray(string &input) {
  std::replace(input.begin(), input.end(), '[', '{');
  std::replace(input.begin(), input.end(), ']', '}');
}

bool cmp(pair<int, int> &a, pair<int, int> &b) { return a.first < b.first; }


long getPrefixSufixAns(vector<long> &diff) {
  if(diff[0]==0) {
    int inc=0;
    for(int i=0;i<diff.size();i++)
      if(diff[i]!=0) {
        inc=i;
        break;
      }
    long ans=diff[inc];
    for(int i=inc+1;i<diff.size();i++) {
      if(diff[i]<diff[i-1]) return LONG_MAX;
      if(diff[i]==0) return LONG_MAX;
      ans+=(diff[i]-diff[inc]);
    }
    return ans;
  } else if(diff[diff.size()-1]==0) {
    int dec=0;
    for(int i=0;i<diff.size();i++) {
      if(diff[i]==0) {
        dec=i-1;
        break;
      }
    }

    long ans=diff[dec];
    for(int i=0;i<dec;i++) {
      if(diff[i]>diff[i-1]) return LONG_MAX;
      if(diff[i]==0) return LONG_MAX;
      ans+=(diff[i]-diff[dec]);
    }
    return ans;
  } else {
    int deE=-1, incE=-1;
    for(int i=0;i<diff.size();i++) {
      if(diff[i]==0) {
        deE=i;
        break;
      }
    }
    for(int i=deE+1;i<diff.size();i++) {
      if(diff[i]!=0) {
        incE = i;
        break;
      }
    }
    if(deE == -1 || incE == -1) return -1;
    long ans=diff[deE-1];
    for(int i=0;i<deE;i++) {
      if(diff[i]==0) return LONG_MAX;
      if(diff[i]>diff[i-1]) return LONG_MAX;
      ans+=(diff[i]-diff[deE-1]);
    }
    ans+=diff[incE];
    for(int i=incE;i<diff.size();i++) {
      if(diff[i]==0) return LONG_MAX;
      if(diff[i]<diff[i-1]) return LONG_MAX;
      ans+=(diff[i]-diff[incE]);
    }
    return ans;
  }
  return -1;
}

long getMinimumOperations (vector<long> source, vector<long> target) {
  vector<long> diff(source.size(), 0);
  for(int i=0;i<source.size();i++) {
    long ad = target[i]-source[i];
    if(ad<0) return -1;
    diff[i]=ad;
  }

  long temp = getPrefixSufixAns(diff);
  if(temp==LONG_MAX) return -1;
  if(temp!=-1) return temp;

  long ans=0;
  int decreasingSeq = -1;
  int increasingSeq = -1;
  int equalSequenceS = -1, equalSequenceE = -1; 

  bool dS = false, dE=false;
  bool iS = false, iE=false;
  bool zeroS = false, zeroE = false;

  debarr(diff, diff.size());


  for(int i=1;i<diff.size();i++) {
    if(diff[i]==diff[i-1]) {
      // started with equal number of required.
      if(decreasingSeq == -1 && increasingSeq==-1) {
        if(equalSequenceS==-1) equalSequenceS = i-1;
      }
    } else if(diff[i]>diff[i-1]) {
      if(increasingSeq==-1 && decreasingSeq==-1) { // only increasing sequence,
        if(equalSequenceS!=-1) {
          increasingSeq=equalSequenceS;
          equalSequenceS = -1;
        }
        else increasingSeq = i-1;
        dE=true;
      } else if(increasingSeq==-1 && decreasingSeq!=-1) {
        if(equalSequenceS!=-1) {
          increasingSeq=equalSequenceS;
          equalSequenceS=-1;
        } 
        else increasingSeq=i; // decreasing is found
        dE=true;
      } else if(!dE) { // in increasing sequence, decrease is not end.
        return -1;
      }
      iS=true;
      iE=false;
      // else we are in increasing sequence
    } else { // we are in decreasing sequence
      if(decreasingSeq==-1) {
        if(equalSequenceS!=-1) {
          decreasingSeq = equalSequenceS;
          equalSequenceS=-1;
        }
        else
          decreasingSeq = i-1;
      }
      else if(iS) // in decreasing sequence, increase is started.
        return -1;
      dS=true;
      dE=false;
    }
  }

  cout<<decreasingSeq<<" "<<increasingSeq<<'\n';

  bool computeDS = decreasingSeq != -1 ? true : false;
  if(computeDS) {
    int upperBound = increasingSeq == -1 ? diff.size() : increasingSeq;
    long dMini=LONG_MAX;
    for(int i=0;i<upperBound;i++) {
      dMini=min(dMini, diff[i]);
    }
    ans+=dMini;
    for(int i=0;i<upperBound;i++) {
      ans+=(diff[i]-dMini);
    }
  }
  bool computeIS = increasingSeq == -1 ? false : true;
  if(computeIS) {
    int curMin=diff[increasingSeq];
    int runnMin=curMin;
    ans+=curMin;
    for(int i=increasingSeq+1;i<diff.size();i++) {
      
    }
  }
  return ans;
}

int main() {
  vector<long> st={1,2,3,3,4,5,}; 
  vector<long> wt={2,3,4,7,8,9};

  cout<<getMinimumOperations(st, wt);
  return 0;
}