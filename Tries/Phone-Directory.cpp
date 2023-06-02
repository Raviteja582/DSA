#include <bits/stdc++.h>
#include <cstddef>
#include <string>
#include <unordered_map>
#include <unordered_set>
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

struct node {
  node *ch[26];
  bool isWord = false;
  node() {
    for (int i = 0; i < 26; i++)
      ch[i] = nullptr;
  }
};

class Solution {
public:
  void findPhone(node *root, vector<string> &curr, string pre) {
    if (root->isWord) {
      curr.push_back(pre);
    }

    for (int i = 0; i < 26; i++) {
      if (root->ch[i] != nullptr) {
        pre.push_back((char)('a' + i));
        findPhone(root->ch[i], curr, pre);
        pre.pop_back();
      }
    }
  }

  vector<vector<string>> displayContacts(int n, string contact[], string s) {
    node *root = new node;
    for (int i = 0; i < n; i++) {
      string st = contact[i];
      node *curr = root;
      for (int j = 0; j < st.size(); j++) {
        int indx = st[j] - 'a';
        if (curr->ch[indx] == nullptr)
          curr->ch[indx] = new node;
        curr = curr->ch[indx];
      }
      curr->isWord = true;
    }

    string pre = "";
    vector<vector<string>> ans;
    node *curr = root;

    for (int i = 0; i < s.size(); i++) {
      vector<string> pp;
      pre.push_back(s[i]);
      int indx = s[i] - 'a';
      curr = (curr == nullptr) ? nullptr : curr->ch[indx];

      if (curr == nullptr) {
        pp.push_back("0");
      } else {
        findPhone(curr, pp, pre);
      }
      ans.push_back(pp);
    }

    return ans;
  }
};

int main() {
  int n;
  cin >> n;
  string arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  string ss;
  cin >> ss;

  Solution sb;
  vector<vector<string>> ans = sb.displayContacts(n, arr, ss);
  for (auto vv : ans) {
    for (auto s : vv)
      cout << s << " ";
    cout << endl;
  }

  return 0;
}