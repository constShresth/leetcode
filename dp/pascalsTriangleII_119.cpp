#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    if (rowIndex == 0) return { 1 };
    if (rowIndex == 1) return { 1,1 };
    vector<vector<int>> pt(rowIndex + 1);
    pt[0] = { 1 };
    pt[1] = { 1,1 };
    for (int i = 2; i < rowIndex + 1; i++) {
      vector<int> v(i + 1);
      v[0] = 1;
      v[i] = 1;
      for (int j = 1; j < i; j++) {
        v[j] = pt[i - 1][j - 1] + pt[i - 1][j];
      }
      pt[i] = v;
    }
    return pt[rowIndex];
  }
};

int main() {



  return 0;
}