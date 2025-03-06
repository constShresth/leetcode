#include <iostream>
using namespace std;

class Solution {
public:
  long long coloredCells(int n) {
    return 1ll * n * n + (n - 1ll) * (n - 1);
    // if (n == 1) return 1;
    // long long ans = 1;
    // for (int i = 1; i < n; i++) {
    //   ans = ans + (4 * i);
    // }
    // return ans;
  }
};

int main() {



  return 0;
}