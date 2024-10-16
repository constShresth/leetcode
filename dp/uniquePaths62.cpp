#include <iostream>
using namespace std;

class Solution {
public:
  int f(int row, int col, int m, int n, vector<vector<int>>& dp) {
    if (row > m - 1 || col > n - 1) return 0;
    if (row == m - 1 || col == n - 1) return 1;
    if (dp[row][col] != -1) return dp[row][col];
    int down = f(row + 1, col, m, n, dp);
    int right = f(row, col + 1, m, n, dp);
    return dp[row][col] = down + right;
  }
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int row = m - 1; row >= 0; row--) {
      for (int col = n - 1; col >= 0; col--) {
        if (row == m - 1 || col == n - 1) dp[row][col] = 1;
        else {
          int down = dp[row + 1][col];
          int right = dp[row][col + 1];
          dp[row][col] = down + right;
        }
      }
    }
    vector<int> prev(n, 0);
    for (int row = m - 1; row >= 0; row--) {
      vector<int> curr(n, 0);
      for (int col = n - 1; col >= 0; col--) {
        if (row == m - 1 || col == n - 1) curr[col] = 1;
        else {
          int down = prev[col];
          int right = curr[col + 1];
          curr[col] = down + right;
        }
      }
      prev = curr;
    }


    // return dp[0][0];
    return prev[0];
  }
};

int main() {



  return 0;
}