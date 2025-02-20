#include <iostream>
using namespace std;

class Solution {
private:
  void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& res, int m, int n) {
    vis[row][col] = 1;
    if (res[row][col] == 'M') {
      res[row][col] = 'X';
      return;
    }
    int count = 0;
    if (res[row][col] == 'E') {
      for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
          int nr = row + i;
          int nc = col + j;
          if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
            if (res[nr][nc] == 'M') {
              count++;
            }
          }
        }
      }
      if (count > 0) {
        res[row][col] = count + '0';
      }
      else {
        res[row][col] = 'B';
      }
    }

    if (res[row][col] == 'B') {
      for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
          int nr = row + i;
          int nc = col + j;
          if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
            if (!vis[nr][nc]) {
              dfs(nr, nc, vis, res, m, n);
            }
          }
        }
      }
    }
  }
public:
  vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    vector<vector<char>> res = board;
    int m = board.size();
    int n = board[0].size();
    int row = click[0];
    int col = click[1];
    vector<vector<int>> vis(m, vector<int>(n, 0));
    dfs(row, col, vis, res, m, n);
    return res;
  }
};

int main() {



  return 0;
}