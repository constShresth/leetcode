#include <iostream>
using namespace std;

class Solution {
private:
  int f(int row, int col, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& moveCost, vector<vector<int>>& dp) {
    if (row == m - 1) return grid[row][col];
    if (dp[row][col] != -1) return dp[row][col];
    int cost = INT_MAX;
    for (int nc = 0; nc < n; nc++) {
      cost = min(cost, grid[row][col] + moveCost[grid[row][col]][nc] + f(row + 1, nc, m, n, grid, moveCost, dp));
    }
    return dp[row][col] = cost;
  }
public:
  int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    int m = grid.size();
    int n = grid[0].size();
    int res = INT_MAX;
    vector<int> next(n, 0);
    vector<int> curr(n, 0);

    for (int col = 0; col < n; col++) next[col] = grid[m - 1][col];

    for (int row = m - 2; row >= 0; row--) {
      for (int col = 0; col < n; col++) {
        int cost = INT_MAX;
        for (int nc = 0; nc < n; nc++) {
          cost = min(cost, grid[row][col] + moveCost[grid[row][col]][nc] + next[nc]);
        }
        curr[col] = cost;
      }
      next = curr;
    }

    for (int col = 0; col < n; col++) res = min(res, next[col]);
    return res;


    // vector<vector<int>> dp(m, vector<int>(n, 0));

    // for (int col = 0; col < n; col++) dp[m - 1][col] = grid[m - 1][col];

    // for (int row = m - 2; row >= 0; row--) {
    //   for (int col = 0; col < n; col++) {
    //     int cost = INT_MAX;
    //     for (int nc = 0; nc < n; nc++) {
    //       cost = min(cost, grid[row][col] + moveCost[grid[row][col]][nc] + dp[row + 1][nc]);
    //     }
    //     dp[row][col] = cost;
    //   }

    // }

    // for (int col = 0; col < n; col++) res = min(res, dp[0][col]);
    // return res;


    // int cost = INT_MAX;
    // vector<vector<int>> dp(m, vector<int>(n, -1));
    // for (int col = 0; col < n; col++) {
    //   cost = min(cost, f(0, col, m, n, grid, moveCost, dp));
    // }
    // return cost;
  }
};

int main() {



  return 0;
}