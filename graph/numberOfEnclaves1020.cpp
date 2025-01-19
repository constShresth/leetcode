#include <iostream>
using namespace std;

class Solution {
public:
  int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
      if (grid[i][0] == 1) {
        q.push({ i,0 });
        vis[i][0] = 1;
      }
      if (grid[i][n - 1] == 1) {
        q.push({ i,n - 1 });
        vis[i][n - 1] = 1;
      }
    }
    for (int j = 1; j < n - 1; j++) {
      if (grid[0][j] == 1) {
        q.push({ 0,j });
        vis[0][j] = 1;
      }
      if (grid[m - 1][j] == 1) {
        q.push({ m - 1,j });
        vis[m - 1][j] = 1;
      }
    }
    vector<int> drow = { -1,0,+1,0 };
    vector<int> dcol = { 0,-1,0,+1 };
    while (!q.empty()) {
      int row = q.front().first;
      int col = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++) {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];
        if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n
          && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
          vis[nrow][ncol] = 1;
          q.push({ nrow,ncol });
        }
      }
    }
    int count = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (!vis[i][j] && grid[i][j] == 1) {
          count++;
        }

      }
    }
    return count;
    // o(n*m), o(n*m)
  }
};

int main() {



  return 0;
}