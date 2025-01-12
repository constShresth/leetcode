#include <iostream>
using namespace std;

class Solution {
public:
  void setRow(int row, int n, vector<vector<int>>& matrix) {
    for (int i = 0; i < n; i++) {
      matrix[row][i] = 0;
    }
  }
  void setCol(int col, int m, vector<vector<int>>& matrix) {
    for (int i = 0; i < m; i++) {
      matrix[i][col] = 0;
    }
  }
  void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<pair<int, int>> v;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          v.push_back({ i,j });
        }
      }
    }
    for (auto pair : v) {
      setRow(pair.first, n, matrix);
      setCol(pair.second, m, matrix);
    }
    // o(mn) + o(mn*(m+n)), o(mn) 
  }
};

int main() {



  return 0;
}