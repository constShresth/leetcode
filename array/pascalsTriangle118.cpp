#include <iostream>
using namespace std;

class Solution {
private:
  // int ncr(int n, int r) {
  //   long long res = 1;
  //   for (int i = 0; i < r; i++) {
  //     res = res * (n - i);
  //     res = res / (i + 1);
  //   }
  //   return res;
  // }
  vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> res;
    res.push_back(1);
    for (int col = 1; col < row; col++) {
      ans = ans * (row - col);
      ans = ans / col;
      res.push_back(ans);
    }
    return res;
  }
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    for (int i = 1; i <= numRows; i++) {
      vector<int> row = generateRow(i);
      res.push_back(row);
    }
    return res;
    // o(n*n)
    // to find the num at a particular row & col use ncr(row-1,col-1);
    // where row & col are 1 based indexed.

    // if (numRows == 1) return { {1} };
    // if (numRows == 2) return { {1},{1,1} };
    // vector<vector<int>> result(numRows);
    // result[0] = { 1 };
    // result[1] = { 1,1 };
    // for (int i = 2; i < numRows; i++) {
    //   vector<int> v(i + 1);
    //   v[0] = 1;
    //   v[i] = 1;
    //   for (int j = 1; j < i; j++) {
    //     v[j] = result[i - 1][j - 1] + result[i - 1][j];
    //   }
    //   result[i] = v;
    // }
    // return result;
  }
};

int main() {



  return 0;
}