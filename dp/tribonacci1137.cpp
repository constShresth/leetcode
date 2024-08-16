#include <iostream>
using namespace std;

class Solution {
public:
  int tribonacci(int n) {
    if (n <= 1) return n;
    if (n == 2) return 1;
    int a = 0, b = 1, c = 1, temp;
    for (int i = 3; i <= n; i++) {
      temp = a + b + c;
      a = b;
      b = c;
      c = temp;
    }
    return c;
  }
};

int main() {



  return 0;
}