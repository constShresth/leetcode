#include <iostream>
using namespace std;

class Solution {
public:
  bool judgeCircle(string moves) {
    int count1 = 0;
    int count2 = 0;
    for (auto it : moves) {
      if (it == 'U') count1++;
      if (it == 'D') count1--;
      if (it == 'L') count2++;
      if (it == 'R') count2--;
    }
    if (count1 != 0 || count2 != 0) return false;
    return true;
  }
};

int main() {



  return 0;
}