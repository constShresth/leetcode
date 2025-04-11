#include <iostream>
using namespace std;

class Solution {
public:
  int countSymmetricIntegers(int low, int high) {
    int cnt = 0;
    for (int i = low; i <= high; i++) {
      string num = to_string(i);
      int n = num.size();
      if (n % 2 == 1) continue;
      int s1 = 0;
      int s2 = 0;
      for (int j = 0; j < n / 2; j++) {
        s1 += num[j];
        s2 += num[n - 1 - j];
      }
      if (s1 == s2) cnt++;
    }
    return cnt;
  }
};

int main() {



  return 0;
}