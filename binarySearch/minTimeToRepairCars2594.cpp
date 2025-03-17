#include <iostream>
using namespace std;

class Solution {
private:
  long long countCars(long long m, vector<int>& ranks) {
    long long count = 0;
    for (auto it : ranks) {
      count += sqrt(m / it);
    }
    return count;
  }
public:
  long long repairCars(vector<int>& ranks, int cars) {
    long long l = 1, r = (long long)ranks[0] * cars * cars;
    long long res = -1;
    while (l <= r) {
      long long m = l + (r - l) / 2;
      long long carsRepaired = countCars(m, ranks);
      if (carsRepaired >= cars) {
        res = m;
        r = m - 1;
      }
      else {
        l = m + 1;
      }
    }
    return res;
  }
};

int main() {



  return 0;
}