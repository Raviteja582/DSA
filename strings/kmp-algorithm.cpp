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


/*
    Explanation: https://www.youtube.com/watch?v=V5-7GzOfADQ
    code: https://www.youtube.com/watch?v=klaWddXp0TM
*/
class Solution {
    public:

      void build_lps(string pat, vector<int> &lps) {

        int m = pat.size();
        // building lps array
        for(int i=1;i<m;i++) {
            int j = lps[i-1];
            while(j>0 && pat[i]!=pat[j]) j=lps[j-1];
            if(pat[i]==pat[j]) j++;
            lps[i]=j;
        }
        pr(lps);
      }

      void kmpAlgo(string text, string pat) {
        int n=text.size(), m=pat.size();
        vector<int> lps(m, 0);
        build_lps(pat, lps);
        // kmp algorithm
        int i=0,j=0;
        while(i<n) {
            if(pat[j]==text[i]) i++,j++;
            if(j==m) {
                pr("matching: ", i-j);
                j=lps[j-1];   
            }
            else if(i<n && pat[j]!=text[i]) {
                if(j!=0)
                    j=lps[j-1];
                else
                    i+=1;
            }
        }
      }
};

int main() {
    // understanding lps array:
    string patts[]= {"abcdabeabf", "abcdeabfabc", "aabcadaabe", "aaaabaacd"};
    for( auto pat: patts){
        Solution sb;
        vector<int> lps(pat.size(),0);
        pr(pat);
        sb.build_lps(pat, lps);
    }
    return 0;
}