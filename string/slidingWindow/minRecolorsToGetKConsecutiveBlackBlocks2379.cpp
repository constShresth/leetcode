#include <iostream>
using namespace std;

class Solution {
public:
  int minimumRecolors(string blocks, int k) {
    int res = INT_MAX;
    int count = 0;
    for (int i = 0; i < k; i++) {
      if (blocks[i] == 'W') count++;
    }
    res = count;
    int l = 1;
    int r = k;
    int n = blocks.size();
    while (r < n) {
      if (blocks[l - 1] == 'B' && blocks[r] == 'W') {
        count++;
      }      
else if (blocks[l - 1] == 'W' && blocks[r] == 'B') {
        count--;
      }
      res = min(res, count);
      l++;
      r++;
    }
    return res;
  }
};

int main() {



  return 0;
}