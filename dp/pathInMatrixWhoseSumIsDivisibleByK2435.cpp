#include <iostream>
using namespace std;

class Solution {
private:
  int mod = 1e9 + 7;
  int f(int row, int col, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int k, int rem) {
    if (row < 0 || col < 0) return 0;
    rem = (rem + grid[row][col]) % k;
    if (row == 0 && col == 0) return rem == 0 ? 1 : 0;

    if (dp[row][col][rem] != -1) return dp[row][col][rem];

    int up = f(row - 1, col, grid, dp, k, rem);
    int left = f(row, col - 1, grid, dp, k, rem);

    return dp[row][col][rem] = (up + left) % mod;
  }
public:
  int numberOfPaths(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1)));
    return f(m - 1, n - 1, grid, dp, k, 0);

  }
};

int main() {



  return 0;
}