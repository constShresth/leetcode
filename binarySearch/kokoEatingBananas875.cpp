#include <iostream>
using namespace std;

class Solution {
public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
    long long sum = 0;
    int high = piles[0];
    for (int i = 0; i < n; i++) {
      sum += piles[i];
      high = max(high, piles[i]);
    }
    int low = (sum + h - 1) / h; // same as ceil(sum/low)
    int res = -1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int time = 0;
      for (int i = 0; i < n; i++) {
        time = time + (piles[i] + mid - 1) / mid;
        // same as ceil(piles[i]/low)
      }
      if (time <= h) {
        res = mid;
        high = mid - 1;
      }
      else low = mid + 1;
    }
    return res;
  }
};

int main() {



  return 0;
}