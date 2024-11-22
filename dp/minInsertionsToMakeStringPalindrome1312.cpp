#include <iostream>
using namespace std;

int main() {

  class Solution {
  public:
    int f(int i, int j, string& s, vector<vector<int>>& dp) {
      if (i > j) return 0;

      if (dp[i][j] != -1) return dp[i][j];

      if (s[i] == s[j]) return dp[i][j] = f(i + 1, j - 1, s, dp);
      else return dp[i][j] = 1 + min(f(i, j - 1, s, dp), f(i + 1, j, s, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
      int n = text1.size();
      int m = text2.size();
      vector<int> prev(m + 1, 0), curr(m + 1, 0);

      // for(int j = 0; j<=m; j++) prev[j] = 0;

      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (text1[i - 1] == text2[j - 1]) curr[j] = 1 + prev[j - 1];

          else curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
      }

      return prev[m];
    }

    int longestPalindromeSubseq(string s) {
      string s2 = s;
      reverse(s2.begin(), s2.end());
      return longestCommonSubsequence(s, s2);
    }
    int minInsertions(string s) {
      int n = s.size();
      int lps = longestPalindromeSubseq(s);
      return n - lps;
      // vector<vector<int>> dp(n, vector<int>(n,-1));
      // return f(0,n-1,s,dp);
    }
  };

  return 0;
}