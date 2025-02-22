#include <iostream>
using namespace std;

class Solution {
private:
  void dfs1(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board, int m, int n) {
    vis[row][col] = 1;
    if (col + 1 < n && board[row][col + 1] == 'X') dfs1(row, col + 1, vis, board, m, n);
  }
  void dfs2(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board, int m, int n) {
    vis[row][col] = 1;
    if (row + 1 < m && board[row + 1][col] == 'X') dfs2(row + 1, col, vis, board, m, n);
  }
public:
  int countBattleships(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    int count = 0;
    vector<vector<int>> vis(m, vector<int>(n, 0));
    for (int row = 0; row < m; row++) {
      for (int col = 0; col < n; col++) {
        if (board[row][col] == 'X') {
          if (row > 0 && board[row - 1][col] == 'X') continue;
          if (col > 0 && board[row][col - 1] == 'X') continue;
          count++;
        }
        // if(board[row][col]=='X' && !vis[row][col]){
        //     if(col+1<n && board[row][col+1]=='X') dfs1(row,col,vis,board,m,n);
        //     else if(row+1<m && board[row+1][col]=='X') dfs2(row,col,vis,board,m,n);
        //     // if it's last row or last col then the node will not be marked as visited 
        //     // but that won't be a problem as the same node will be adjacent of any other
        //     // 'X' node as no one was adjacent to it.
        //     count++;
        // }
      }
    }
    return count;
  }
};

int main() {



  return 0;
}