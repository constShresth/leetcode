#include <iostream>
using namespace std;

class Solution {
public:
  int minOperations(vector<vector<int>>& grid, int x) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> vec;
    int rem = grid[0][0] % x;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int curr_rem = grid[i][j] % x;
        if (curr_rem != rem) {
          return -1;
        }
        vec.push_back(grid[i][j]);
      }
    }
    sort(vec.begin(), vec.end());
    int size = vec.size();
    int index = size / 2;
    int res = 0;
    for (int i = 0; i < size; i++) {
      if (i == index) continue;
      res += abs(vec[index] - vec[i]) / x;
    }
    return res;
  }
};

int main() {



  return 0;
}