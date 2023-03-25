#include <bits/stdc++.h>
#include <cstddef>
#include <cstring>
using namespace std;

class Solution {
public:
  void test() {
    string line = "230-1234-435-6444-235-245-";

    // Vector of string to save tokens
    vector<string> tokens;

    // stringstream class check1
    stringstream check1(line);

    string intermediate;

    // Tokenizing w.r.t. space '-'
    while (getline(check1, intermediate, '-')) {
      tokens.push_back(intermediate);
    }

    // Printing the token vector
    for (int i = 0; i < tokens.size(); i++)
      cout << tokens[i] << '\n';
  }
};

int main() { 
    Solution sb;
    sb.test();
    return 0; 
}