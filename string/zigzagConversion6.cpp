#include <iostream>
using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1 || numRows >= s.size()) return s;
    string res;
    for (int row = 0; row < numRows; row++) {
      int increment = (numRows - 1) * 2;
      int i = row;
      while (i < s.size()) {
        res.push_back(s[i]);
        if (row > 0 && row < numRows - 1 && (i + increment - (2 * row)) < s.size()) {
          res.push_back(s[i + increment - (2 * row)]);
        }
        i += increment;
      }
    }
    return res;
  }
};

int main() {



  return 0;
}