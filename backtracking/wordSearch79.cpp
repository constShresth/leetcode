#include <iostream>
using namespace std;

class Solution {
  bool dfs(int row, int col, int ind, vector<vector<char>>& board, string& word, int m, int n) {
    if (ind == word.size() - 1) return board[row][col] == word[ind];

    char temp = board[row][col];
    board[row][col] = '#';

    bool res = false;

    vector<int> dr = { -1,0,+1,0 };
    vector<int> dc = { 0,-1,0,+1 };
    for (int i = 0; i < 4; i++) {
      int nr = row + dr[i];
      int nc = col + dc[i];
      if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == word[ind + 1]) {
        if (dfs(nr, nc, ind + 1, board, word, m, n)) {
          res = true;
          break;
        };
      }
    }
    board[row][col] = temp;

    return res;
  }
public:
  bool exist(vector<vector<char>>& board, string word) {
    //hint: minimise the number of recursive calls with if statements
    int m = board.size();
    int n = board[0].size();
    int k = word.size();
    for (int row = 0; row < m; row++) {
      for (int col = 0; col < n; col++) {
        if (board[row][col] == word[0]) {
          if (dfs(row, col, 0, board, word, m, n)) return true;;
        }
      }
    }
    return false;
  }
};

int main() {



  return 0;
}