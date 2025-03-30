#include <iostream>
using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // transpose matrix
    // o((n/2)*(n/2))
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
    // o(n*(n/2))
    for (int i = 0; i < n; i++) {
      reverse(matrix[i].begin(), matrix[i].end());
    }

    // int n = matrix.size();
    // vector<vector<int>> res(n, vector<int>(n));
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < n; j++) {
    //     res[j][n - i - 1] = matrix[i][j];
    //   }
    // }
    // matrix = res;
    // o(n*n), o(n*n)
  }
};

int main() {



  return 0;
}