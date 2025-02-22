#include <iostream>
using namespace std;

class Solution {
private:
  int dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, int m, int n) {
    vis[row][col] = 1;
    vector<int> dr = { -1,0,+1,0 };
    vector<int> dc = { 0,-1,0,+1 };
    int res = 4;
    for (int i = 0; i < 4; i++) {
      int nr = row + dr[i];
      int nc = col + dc[i];
      if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc]) {
        res--;
        if (!vis[nr][nc]) res = res + dfs(nr, nc, vis, grid, m, n);
      }
    }
    return res;
  }
public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int perimeter = 0;
    // vector<vector<int>> vis(m,vector<int>(n,0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j]) {
          perimeter += 4;
          if (i > 0 && grid[i - 1][j] == 1) perimeter -= 2;
          if (j > 0 && grid[i][j - 1] == 1) perimeter -= 2;
        }
        // if(grid[i][j] && !vis[i][j]){
        //     int count = 0;
        //     return dfs(i,j,vis,grid,m,n);
        // }
      }
    }
    return perimeter;
  }
};

int main() {



  return 0;
}