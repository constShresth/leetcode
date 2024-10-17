#include <iostream>
using namespace std;

class Solution {
public:
  int mod = (int)(7 + 1e9);
  int f(int row, int col, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    if (row > m - 1 || col > n - 1) return 0;
    if (grid[row][col] == 1) return 0;
    if (row == m - 1 && col == n - 1) return 1;

    if (dp[row][col] != -1) return dp[row][col];

    int down = f(row + 1, col, m, n, grid, dp);
    int right = f(row, col + 1, m, n, grid, dp);

    return dp[row][col] = down + right;

  }

  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(0, 0, m, n, obstacleGrid, dp);

    //below code gives integer overflow
    // for(int row = m-1; row>=0; row--){
    //     for(int col = n-1; col>=0; col--){
    //         if(obstacleGrid[row][col]==1) dp[row][col] = 0;
    //         else if(row==m-1 && col==n-1) dp[row][col] = 1;
    //         else{
    //             int down = (row+1<=m-1) ? dp[row+1][col] : 0;
    //             int right = (col+1<=n-1) ? dp[row][col+1] : 0;

    //             dp[row][col] = down+right;
    //         }
    //     }
    // }

    // return dp[0][0];

  }
};

int main() {



  return 0;
}