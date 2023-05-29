/*
    Link: https://www.interviewbit.com/problems/regular-expression-ii/

    Theory:
        '.' -> matches any character
        '*' -> matches zero or more of the previous character

            i.e. '.*' -> "", "..", "...", "....", .....
                 'a*' -> "", "a", "aa", "aaa", ....
    Case Studies:
        A = regular Exp,
        B = normal string
        lastIndex = the index of the last character or '.' which current '*' is
   repeating lastChar = the character or '.' that current '*' is repeating.

        if A[i]=='*':
            if lastChar = x and B[j]=x i.e. ( lastChar == B[j])
               lastChar = . and B[j]=some character (lastChar == '.')

                then dp[i][j] = dp[lastIndex][j-1] || -> we checking with
   previous indices in both A and B dp[lastIndex][j]   || -> we checking with
   previous matched sequence if not using * dp[i][j-1]            -> we checking
   whether the pattern already matched previously else dp[i][j] =
   dp[lastIndex][j] -> we checking with previous matched sequence if not using *

        else if A[i]=='.'
            if dp[i-1][j-1] -> if we subsititue B[i] in A[i], then checking
   previous sequence dp[i][j] = dp[i-1][j-1] lastChar = '.' lastIndex = i else
                dp[i][j]=false
        else if A[i]==B[j] && dp[i-1][j-1] -> checking the character to
   character and previous matched sequence dp[i][j] = true; else dp[i][j] =
   false
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isMatch(string A, string B) {
    string temp = B;
    B = A;
    A = "";
    // removing ** to * as it only follows previous character or '.'
    for (int i = 0; i < temp.size(); i++) {
      if (temp[i] == '*') {
        if (A[A.size() - 1] != '*')
          A.push_back(temp[i]);
      } else
        A.push_back(temp[i]);
    }
    int n = A.size(), m = B.size();

    bool dp[n + 1][m + 1];
    memset(dp, false, sizeof(dp));

    dp[0][0] = true;
    char lastChar;
    int lastInd = 0;
    for (int i = 1; i <= n; i++) {

      // processing character of regex to empty string   
      if (A[i - 1] == '*') {
        dp[i][0] = dp[lastInd][0]; // decide to put empty char in '*'
      } else if (A[i - 1] == '.') {
        dp[i][0] = false; // we cannot put empty char in '.'
      } else {
        if (i < n && A[i] == '*') { // if next char in regex is '*', then don't process this
          lastChar = A[i - 1];
          lastInd = i - 1;
          continue;
        }
        dp[i][0] = false;
        lastChar = A[i - 1];
      }

      for (int j = 1; j <= m; j++) {
        if (A[i - 1] == '*') {
          if (lastChar == B[j - 1] || lastChar == '.')
            dp[i][j] = dp[lastInd][j - 1] || dp[lastInd][j] || dp[i][j - 1];
          else
            dp[i][j] = dp[lastInd][j];
        } else if (A[i - 1] == '.') {
          if (dp[i - 1][j - 1]) {
            dp[i][j] = true;
            lastChar = '.';
            lastInd = i;
          } else
            dp[i][j] = false;
        } else if (A[i - 1] == B[j - 1] && dp[i - 1][j - 1]) {
          dp[i][j] = true;
        } else {
          dp[i][j] = false;
        }
      }
    }

    return dp[n][m];
  }
};

/*
    Example:
        1. abcbcd -> a.*c.*d ( here .* repeats any character multiple times)
        2. aa -> .*
        3. ab -> .*
        4. aeed -> a.*c*d
*/

int main() { return 0; }
