#include <iostream>
using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    queue<pair<pair<int, int>, int>> q;
    for (int row = 0; row < m; row++) {
      for (int col = 0; col < n; col++) {
        if (grid[row][col] == 2) {
          q.push({ {row,col},0 });
          vis[row][col] = 1;
        }
      }
    }

    int tm = 0;

    while (!q.empty()) {
      int row = q.front().first.first;
      int col = q.front().first.second;
      int t = q.front().second;
      q.pop();
      tm = max(tm, t);
      vector<int> drow = { -1,0,+1,0 };
      vector<int> dcol = { 0,-1,0,+1 };
      for (int i = 0; i < 4; i++) {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];
        if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
          q.push({ {nrow,ncol},t + 1 });
          vis[nrow][ncol] = 1;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1 && !vis[i][j]) return -1;
      }
    }
    return tm;
    // o(m*n), o(m*n)
  }
};

int main() {



  return 0;
}