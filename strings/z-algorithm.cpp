#include<bits/stdc++.h>
#include <vector>
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
/**
 * Date 10/31/2015
 * @author Tushar Roy
 *
 * Z algorithm to pattern matching
 *
 * Time complexity - O(n + m)
 * Space complexity - O(n + m)
 *
 * http://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/
 * http://www.utdallas.edu/~besp/demo/John2010/z-algorithm.htm
 */
class Solution {
    public:
    vector<int> calculateZ(string txt) {
        vector<int> z(txt.size(), 0);
        int left = 0;
        int right = 0;
        for(int k = 1; k < txt.size(); k++) {
            if(k > right) {
                left = right = k;
                while(right < txt.size() && txt[right] == txt[right - left]) {
                    right++;
                }
                z[k] = right - left;
                right--;
            } else {
                //we are operating inside box
                int k1 = k - left;
                pr(k,right, left,k1);
                //if value does not stretches till right bound then just copy it.
                if(z[k1] < right - k + 1) {
                    pr(k1, right-k+1);
                    z[k] = z[k1];
                } else { //otherwise try to see if there are more matches.
                    left = k;
                    while(right < txt.size() && txt[right] == txt[right - left]) {
                        right++;
                    }
                    z[k] = right - left;
                    right--;
                }
            }
        }
        return z;
    }

    /**
     * Returns list of all indices where pattern is found in text.
     */
    void matchPattern(string text, string pattern) {
        string ss = text;
        ss.push_back('$');
        ss.append(pattern);

        vector<int> zz = calculateZ(ss);

        for(int i = 0; i < zz.size(); i++) {
            if(zz[i] == pattern.size()) {
                pr(i - pattern.size() - 1);
            }
        }
    }
};

int main() {
    // string text = "aaabcxyzaaaabczaaczabbaaaaaabc";
    // string pattern = "aaabc";

    string pat = "aabxaabxcaabxaabxay";
    Solution sb;
    vector<int> z = sb.calculateZ(pat);
    pr(z); 
    return 0;
}