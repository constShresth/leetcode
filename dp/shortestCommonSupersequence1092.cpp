#include <iostream>
using namespace std;

class Solution {
public:
  string shortestCommonSupersequence(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    //lcs code
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int j = 0; j <= m; j++) dp[0][j] = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {

        if (str1[i - 1] == str2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];

        else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

      }
    }
    int i = n;
    int j = m;
    string ans = "";
    while (i > 0 && j > 0) {
      if (str1[i - 1] == str2[j - 1]) {
        ans.push_back(str1[i - 1]);
        i--;
        j--;
      }      
else if (dp[i - 1][j] > dp[i][j - 1]) {
        ans.push_back(str1[i - 1]); // 0 based indexing
        i--;
      }
      else {
        ans.push_back(str2[j - 1]);
        j--;
      }
    }
    while (i > 0) {
      ans.push_back(str1[i - 1]);
      i--;
    }
    while (j > 0) {
      ans.push_back(str2[j - 1]);
      j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;


  }
};

int main() {



  return 0;
}