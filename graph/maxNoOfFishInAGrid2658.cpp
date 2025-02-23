#include <iostream>
using namespace std;

class Solution {
private:
  void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, int& count, int m, int n) {
    vis[row][col] = 1;
    count += grid[row][col];
    vector<int> dr = { -1,0,+1,0 };
    vector<int> dc = { 0,-1,0,+1 };
    for (int i = 0; i < 4; i++) {
      int nr = row + dr[i];
      int nc = col + dc[i];
      if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc]>0 && !vis[nr][nc]) {
        dfs(nr, nc, vis, grid, count, m, n);
      }
    }
  }
public:
  int findMaxFish(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int maxi = 0;
    vector<vector<int>> vis(m, vector<int>(n, 0));
    for (int row = 0; row < m; row++) {
      for (int col = 0; col < n; col++) {
        if (grid[row][col] > 0 && !vis[row][col]) {
          int count = 0;
          dfs(row, col, vis, grid, count, m, n);
          maxi = max(maxi, count);
        }
      }
    }
    return maxi;
  }
};

int main() {



  return 0;
}