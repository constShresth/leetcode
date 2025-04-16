#include <iostream>
using namespace std;

class Solution {
private:
  long long mod = 1e9 + 7;
  long long findPower(long long a, long long b) {
    if (b == 0) return 1;
    long long x = findPower(a, b / 2);
    long long res = (x * x) % mod;
    if (b % 2 != 0) res = (res * a) % mod;
    return res;
  }
public:
  int countGoodNumbers(long long n) {
    // no. of odd indices => n/2
    // no. of even indices => (n+1)/2
    // 4 option at odd position
    // 5 option at even position
    return (findPower(5, (n + 1) / 2) * findPower(4, (n / 2))) % mod;
  }
};

int main() {



  return 0;
}