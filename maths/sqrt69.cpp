#include <iostream>
using namespace std;

class Solution {
public:
  int mySqrt(int x) {
    int l = 0, r = x;
    int result = 0;
    while (l <= r) {
      int mid = l + ((r - l) / 2);
      long long square = static_cast<long long>(mid) * mid;
      if (square < x) {
        l = mid + 1;
        result = mid;
      }
      else if (square > x) {
        r = mid - 1;
      }
      else {
        return mid;
      }
    }
    return result;
  }
};

int main() {



  return 0;
}