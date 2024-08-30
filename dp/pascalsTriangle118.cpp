#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    if (numRows == 1) return { {1} };
    if (numRows == 2) return { {1},{1,1} };
    vector<vector<int>> result(numRows);
    result[0] = { 1 };
    result[1] = { 1,1 };
    for (int i = 2; i < numRows; i++) {
      vector<int> v(i + 1);
      v[0] = 1;
      v[i] = 1;
      for (int j = 1; j < i; j++) {
        v[j] = result[i - 1][j - 1] + result[i - 1][j];
      }
      result[i] = v;
    }
    return result;
  }
};

int main() {



  return 0;
}