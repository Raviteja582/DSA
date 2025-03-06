#include <bits/stdc++.h>
#include <vector>
using namespace std;

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
template <class T> void dbs(const string &str, T t) {
  cerr << str << " : " << t << "\n";
}
template <class T, class... S> void dbs(string str, T t, S... s) {
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

class Solution {
public:
  string longestPalindrome(string s) {
    string tmp = "$";
    int maxInd = 0, maxSize = 0;
    for (char c : s) {
      tmp.push_back('#');
      tmp.push_back(c);
    }
    tmp.push_back('#');
    tmp.push_back('@');

    vector<int> v(tmp.size(), 0);
    int C = 0, R = 0;
    for (int i = 1; i < v.size(); i++) {
      int mirr = 2 * C - i;
      if (i < R) {
        v[i] = min(R - i, v[mirr]);
      }

      while (tmp[i + (1 + v[i])] == tmp[i - (1 + v[i])])
        v[i]++;

      if (i + v[i] > R) {
        C = i;
        R = 1 + v[i];
      }

      if (v[i] > maxSize) {
        maxSize = v[i];
        maxInd = i;
      }
    }

    pr(tmp);
    pr(maxInd, maxSize);
    string ans = "";
    for (int i = maxInd - maxSize; i <= (maxInd + maxSize); i++) {
      if (tmp[i] != '#' && tmp[i] != '$' && tmp[i] != '@')
        ans.push_back(tmp[i]);
    }
    return ans;
  }
};

class Manacher {
  vector<int> p;

public:
  void build(string s) {
    string t;
    for (auto x : s) {
      t.push_back('#');
      t.push_back(x);
    }
    run_manacher(t + "#");
  }

  void run_manacher(string s) {
    int n = s.size();
    p.assign(n, 1);
    int l = 1, r = 1;

    for (int i = 1; i < n; i++) {
    //   pr(l,r,i,(l+r-i));
      if(i<r) {
          p[i] = max(0, min(r - i, p[l + r - i]));
      }
      while ((i - p[i] >= 0) && (i + p[i] < n) && s[i - p[i]] == s[i + p[i]])
        p[i]++;

      if ((i + p[i]) > r) {
        l = i - p[i];
        r = i + p[i];
      }
    }
  }

  int getLongest(int cen, int odd) {
    int pos = 2 * cen + 1 + (!odd);
    return p[pos] - 1;
  }

  bool checkPalindrome(int l, int r) {
    if ((r - l + 1) <= getLongest((l + r) / 2, l % 2 == r % 2)) {
      return true;
    } else {
      return false;
    }
  }

  pair<int, string> longestPalindrome(string s) {
    build(s);
    debarr(p, p.size());
    int ans = 0;
    string str = "";

    int ind, val = 0;
    for (int i = 0; i < p.size(); i++) {
      if (p[i] > val) {
        val = p[i];
        ind = i;
      }
    }

    int orig = (ind - 1) / 2;
    val -= 1;
    pr(orig, val);
    if (ind & 1) {
      int left = orig - (val - 1) / 2;
      str = s.substr(left, val);
    } else {
      int left = 1 + (orig - (val) / 2);
      str = s.substr(left, val);
    }

    return {val, str};

    // for (int i = 0; i < s.size(); i++) {
    //   int odd = getLongest(i, 1), even = getLongest(i, 0);
    //   if (odd > ans) {
    //     ans = odd;
    //     int left = i - (odd - 1) / 2, right = i + (odd - 1) / 2;
    //     str = s.substr(left, right + 1);
    //   }
    //   if (even > ans) {
    //     ans = even;
    //     int left = i - (even - 1) / 2, right = i + (even) / 2;
    //     str = s.substr(left, right);
    //   }
    // }
    // return {ans, str};
  }
};

int main() {
  string inp = "a";
  Solution sb;
  // pr(sb.longestPalindrome(inp));

  Manacher m;
  cout << m.longestPalindrome("babad");
  return 0;
}