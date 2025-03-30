#include <iostream>
using namespace std;

class Solution {
private:
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
public:
  void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int col0 = 1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          if (j != 0) matrix[0][j] = 0;
          else col0 = 0;
        }
      }
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }
    if (matrix[0][0] == 0) {
      for (int j = 0; j < n; j++) matrix[0][j] = 0;
    }
    if (col0 == 0) {
      for (int i = 0; i < m; i++) matrix[i][0] = 0;
    }
    // o(2mn)


    // int m = matrix.size();
    // int n = matrix[0].size();
    // vector<int> row(m, 0);
    // vector<int> col(n, 0);
    // for (int i = 0; i < m; i++) {
    //   for (int j = 0; j < n; j++) {
    //     if (matrix[i][j] == 0) {
    //       row[i] = 1;
    //       col[j] = 1;
    //     }
    //   }
    // }
    // for (int i = 0; i < m; i++) {
    //   for (int j = 0; j < n; j++) {
    //     if (row[i] || col[j]) {
    //       matrix[i][j] = 0;
    //     }
    //   }
    // }
    // o(2*mn), o(m+n)


    // int m = matrix.size();
    // int n = matrix[0].size();
    // vector<pair<int, int>> v;
    // for (int i = 0; i < m; i++) {
    //   for (int j = 0; j < n; j++) {
    //     if (matrix[i][j] == 0) {
    //       v.push_back({ i,j });
    //     }
    //   }
    // }
    // for (auto pair : v) {
    //   setRow(pair.first, n, matrix);
    //   setCol(pair.second, m, matrix);
    // }
    // o(mn) + o(mn*(m+n)), o(mn) 
  }
};

int main() {



  return 0;
}