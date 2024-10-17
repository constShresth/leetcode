#include <iostream>
using namespace std;

class Solution {
public:
  int f(int row, int col, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    if (row > m - 1 || col > n - 1) return INT_MAX;
    if (row == m - 1 && col == n - 1) return grid[row][col];

    if (dp[row][col] != -1) return dp[row][col];

    int down = f(row + 1, col, m, n, grid, dp);
    int right = f(row, col + 1, m, n, grid, dp);

    return dp[row][col] = grid[row][col] + min(down, right);
  }
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    // vector<vector<int>> dp(m,vector<int>(n,-1));

    // for(int row = m-1; row>=0; row--){
    //     for(int col = n-1; col>=0; col--){
    //         if(row==m-1 && col==n-1) dp[row][col] = grid[row][col];
    //         else{

    //             int down = (row<m-1) ? dp[row+1][col] : INT_MAX;
    //             int right = (col<n-1) ? dp[row][col+1] : INT_MAX;

    //             dp[row][col] = grid[row][col] + min(down,right);
    //         }
    //     }
    // }

    vector<int> prev(n, -1);

    for (int row = m - 1; row >= 0; row--) {
      vector<int> curr(n, -1);
      for (int col = n - 1; col >= 0; col--) {
        if (row == m - 1 && col == n - 1) curr[col] = grid[row][col];
        else {

          int down = (row < m - 1) ? prev[col] : INT_MAX;
          int right = (col < n - 1) ? curr[col + 1] : INT_MAX;

          curr[col] = grid[row][col] + min(down, right);
        }
      }
      prev = curr;
    }

    // return f(0,0,m,n,grid,dp);
    return prev[0];
  }
};

int main() {



  return 0;
}