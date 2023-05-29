#include<bits/stdc++.h>
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

class Solution {
    public:
    int romanToInt(string s) {
        unordered_map<string, int> m;
        m["I"]=1, m["V"]=5, m["X"]=10;
        m["L"]=50, m["C"]=100, m["D"]=500, m["M"]=1000;
        
        //special
        m["IV"]=4, m["IX"]=9;
        m["XL"]=40, m["XC"]=90;
        m["CD"]=400, m["CM"]=900;
        
        int ans=0;
        for(int i=0;i<s.size();i++) {
            string tmp = "";
            if((i+1)<s.size()) {
                tmp.push_back(s[i]);
                tmp.push_back(s[i+1]);
                if(m.find(tmp)!=m.end()) {
                    ans+=m.at(tmp);
                    i+=1;
                } else {
                    tmp.pop_back();
                    if(m.find(tmp)!=m.end()) {
                        ans+=m.at(tmp);
                    }
                }
            }
            // went above if block...
            if(tmp.size()==0) {
                tmp.push_back(s[i]);
                if(m.find(tmp)!=m.end()) {
                    ans+=m.at(tmp);
                }
            }
        }

        return ans;
    }
};

int main() {
    string st[]={"LVIII", "III", "MCMXCIV"};
    Solution sb;
    for(string x: st){
        pr(sb.romanToInt(x));
    }
    return 0;
}