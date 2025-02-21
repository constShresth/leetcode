#include <iostream>
using namespace std;

class Solution {
private:
  void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, int& area, int m, int n) {
    vis[row][col] = 1;
    area++;
    vector<int> dr = { -1,0,+1,0 };
    vector<int> dc = { 0,-1,0,+1 };
    for (int i = 0; i < 4; i++) {
      int nr = row + dr[i];
      int nc = col + dc[i];
      if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] && !vis[nr][nc]) {
        dfs(nr, nc, vis, grid, area, m, n);
      }
    }
  }
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    int maxArea = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] && !vis[i][j]) {
          int area = 0;
          dfs(i, j, vis, grid, area, m, n);
          maxArea = max(maxArea, area);
        }
      }
    }
    return maxArea;
  }
};

int main() {



  return 0;
}