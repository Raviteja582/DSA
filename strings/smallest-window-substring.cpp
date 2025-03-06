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

bool isValid(string& s, string& p, int mid, int& start) {
    // Count the frequency of each character in p
    int count[256];
    memset(count, 0, sizeof(count));

    pr(s, p, mid, start);

    // Stores number of distinct characters in p
    int distinct = 0;

    // Count the frequency of each character in p
    for (char x : p) {
        if (count[x] == 0)
            distinct++;
        count[x]++;
    }

    // Stores the number of characters in a substring of size
    // mid in s whose frequency is the same as the frequency in p
    int curr_count = 0;
    for (int i = 0; i < s.size(); i++) {
        count[s[i]]--;
        if (count[s[i]] == 0) {
            curr_count++;
        }

        // pr(i, mid, mid-1);
        if (i >= mid) {
            count[s[i - mid]]++;
            if (count[s[i - mid]] == 1) {
                curr_count--;
            }
        }

        if (i >= mid - 1) {
            // Substring of length mid found which contains
            // all the characters of p
            pr(i, curr_count, distinct);
            if (curr_count == distinct) {
                start = (i - mid) + 1;
                return true;
            }
        }
    }

    return false;
}

string smallestWindow(string s, string p) {
    int m = s.length();
    int n = p.length();

    // If s is smaller than p, it's impossible
    if (m < n) return "-1"; 

    int minLength = INT_MAX;

    // Lower bound and Upper Bound for Binary Search
    // The smallest valid window size is n (size of p)
    int low = n, high = m; 

    // Stores starting index of the min-length substring
    int idx = -1;

    // Applying Binary Search on the answer
    while (low <= high) {
        int mid = (low + high) / 2;
        int start;

        // If a substring of length mid is found which
        // contains all the characters of p, then
        // update minLength and high, otherwise update low
        if (isValid(s, p, mid, start)) {
          pr(true);
            if (mid < minLength) {
                minLength = mid;
                idx = start;
            }
            high = mid - 1;
        } else {
          pr(false);
            low = mid + 1;
        }
    }

    if (idx == -1) return "-1";

    return s.substr(idx, minLength);
}

int main() {
    string s = "timetopractice";
    string p = "toc";

    cout << smallestWindow(s, p) << endl; 

    return 0;
}
