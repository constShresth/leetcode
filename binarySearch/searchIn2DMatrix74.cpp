#include <iostream>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int low = 0, high = (m * n) - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int row = mid / n;
      int col = mid % n;
      if (matrix[row][col] == target) return true;
      else if (matrix[row][col] < target) low = mid + 1;
      else high = mid - 1;
    }
    return false;
    // o(log(m*n))

    // for(int row = 0; row<m; row++){
    //     if(matrix[row][0] <= target && target <= matrix[row][n-1]){
    //         int ind = lower_bound(matrix[row].begin(), matrix[row].end(), target) - matrix[row].begin();
    //         if(ind != n && matrix[row][ind] == target) return true;
    //         else return false;
    //     }
    // }
    // return false;
    // o(m + log(n))
  }
};

int main() {



  return 0;
}