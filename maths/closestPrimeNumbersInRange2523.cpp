#include <iostream>
using namespace std;

class Solution {
private:
  bool isPrime(int n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) return false;
    }
    return true;
  }
public:
  vector<int> closestPrimes(int left, int right) {
    // vector<int> vec;
    vector<int> res = { -1,-1 };
    int p1 = -1;
    int p2 = -1;
    int minDiff = INT_MAX;
    for (int i = left; i <= right; i++) {
      if (isPrime(i)) {
        p1 = p2;
        p2 = i;
      };
      if (p1 != -1) {
        int diff = p2 - p1;
        if (diff < minDiff) {
          res = { p1,p2 };
          minDiff = diff;
        }
      }
    }

    // int n = vec.size();
    // vec.size() is an unsigned integer so 0 - 1 = -1 will be a very big number

    //   int minDiff = INT_MAX;
    // for (int i = 0; i < n - 1; i++) {
    //   int diff = vec[i + 1] - vec[i];
    //   if (diff < minDiff) {
    //     res = { vec[i],vec[i + 1] };
    //     minDiff = diff;
    //   }
    // }

    return res;
  }
};

int main() {



  return 0;
}