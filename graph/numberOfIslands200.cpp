#include <iostream>
using namespace std;

class Solution {
private:
  void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
    vis[row][col] = true;
    queue<pair<int, int>> q;
    q.push({ row,col });
    int m = grid.size();
    int n = grid[0].size();
    while (!q.empty()) {
      int row = q.front().first;
      int col = q.front().second;
      q.pop();
      vector<int> drow = { -1,0,+1,0 };
      vector<int> dcol = { 0,-1,0,+1 };
      for (int i = 0; i < 4; i++) {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];
        if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
          vis[nrow][ncol] = true;
          q.push({ nrow,ncol });
        }

      }
    }
  }
public:
  int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    int cnt = 0;
    for (int row = 0; row < m; row++) {
      for (int col = 0; col < n; col++) {
        if (grid[row][col] == '1' && !vis[row][col]) {
          cnt++;
          bfs(row, col, grid, vis);
        }
      }
    }
    return cnt;
  }
};

int main() {



  return 0;
}