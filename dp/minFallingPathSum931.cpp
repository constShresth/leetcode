#include <iostream>
using namespace std;

class Solution {
public:
  int f(int row, int col, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    if (col<0 || col>n - 1) return 1e9;
    if (row == n - 1) return matrix[row][col];

    if (dp[row][col] != -1) return dp[row][col];

    int rdg = 1e9;
    if (col > 0) rdg = f(row + 1, col - 1, n, matrix, dp);
    int down = f(row + 1, col, n, matrix, dp);
    int ldg = 1e9;
    if (col < n - 1) ldg = f(row + 1, col + 1, n, matrix, dp);

    return dp[row][col] = matrix[row][col] + min(rdg, min(down, ldg));
  }
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int mini = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // for(int i = 0; i<n; i++){
    //     mini = min(mini,f(0,i,n,matrix,dp));
    // }
    // dp[n-1] = matrix[n-1];
    // for(int row=n-2; row>=0; row--){
    //     for(int col = n-1; col>=0; col--){
    //         int rdg = 1e9;
    //         if(col>0) rdg = dp[row+1][col-1];
    //         int down = dp[row+1][col];
    //         int ldg = 1e9;
    //         if(col<n-1) ldg = dp[row+1][col+1];

    //         dp[row][col] = matrix[row][col] + min(rdg,min(down,ldg));
    //     }
    // }
    vector<int> prev(n, 0);
    prev = matrix[n - 1];
    for (int row = n - 2; row >= 0; row--) {
      vector<int> curr(n, 0);
      for (int col = n - 1; col >= 0; col--) {
        int rdg = 1e9;
        if (col > 0) rdg = prev[col - 1];
        int down = prev[col];
        int ldg = 1e9;
        if (col < n - 1) ldg = prev[col + 1];

        curr[col] = matrix[row][col] + min(rdg, min(down, ldg));
      }
      prev = curr;
    }

    for (int col = 0; col < n; col++) {
      mini = min(mini, prev[col]);
    }

    return mini;
  }
};

int main() {



  return 0;
}