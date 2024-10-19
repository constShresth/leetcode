#include <iostream>
using namespace std;

class Solution {
public:
  int f(int row, int col, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
    if (col > row) return 1e7;
    if (row == n - 1) return triangle[row][col];

    if (dp[row][col] != -1) return dp[row][col];

    int down = f(row + 1, col, n, triangle, dp);
    int rd = f(row + 1, col + 1, n, triangle, dp);

    return dp[row][col] = triangle[row][col] + min(down, rd);

  }

  int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    // vector<vector<int>> dp(n, vector<int>(n,-1));
    // dp[n-1] = triangle[n-1];
    // for(int row = n-2; row>=0; row--){
    //     for(int col = row; col>=0; col--){
    //         int down = dp[row+1][col];
    //         int rd = dp[row+1][col+1];

    //         dp[row][col] = triangle[row][col] + min(down,rd);
    //     }
    // }
    vector<int> prev = triangle[n - 1];
    for (int row = n - 2; row >= 0; row--) {
      vector<int> curr(n, 0);
      for (int col = row; col >= 0; col--) {
        int down = prev[col];
        int rd = prev[col + 1];

        curr[col] = triangle[row][col] + min(down, rd);
      }
      prev = curr;
    }

    // return f(0,0,n,triangle,dp);
    return prev[0];
  }
};

int main() {



  return 0;
}