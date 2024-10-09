#include <iostream>
using namespace std;

class Solution {
public:
  string convertToTitle(int columnNumber) {
    string result;
    while (columnNumber > 0) {
      int offset = (columnNumber - 1) % 26;
      result.push_back(char(65 + offset));
      columnNumber = (columnNumber - 1) / 26;
    }

    reverse(result.begin(), result.end());
    return result;
  }
};

int main() {



  return 0;
}