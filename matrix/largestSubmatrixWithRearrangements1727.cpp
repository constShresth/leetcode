#include <iostream>
using namespace std;

class Solution {
public:
  int largestSubmatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> grid = matrix;
    for (int col = 0; col < n; col++) {
      for (int row = 1; row < m; row++) {
        if (grid[row - 1][col] > 0 && grid[row][col] > 0) {
          grid[row][col] = grid[row - 1][col] + 1;
        }
      }
    }
    for (int row = 0; row < m; row++) {
      sort(grid[row].rbegin(), grid[row].rend());
    }
    int ans = INT_MIN;
    for (int row = 0; row < m; row++) {
      int cnt = 1;
      for (int col = 0; col < n; col++) {
        ans = max(ans, grid[row][col] * cnt);
        cnt++;
      }
    }
    return ans;
  }
};

int main() {



  return 0;
}