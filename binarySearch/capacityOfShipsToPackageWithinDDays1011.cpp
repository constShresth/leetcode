#include <iostream>
using namespace std;

class Solution {
public:
  int shipWithinDays(vector<int>& weights, int days) {
    int n = weights.size();
    int high = 0;
    int low = INT_MIN;
    for (int i = 0; i < n; i++) {
      high += weights[i];
      low = max(low, weights[i]);
    }
    int ans = -1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int cnt = 0;
      int wt = 0;
      for (int i = 0; i < n; i++) {
        wt += weights[i];
        if (wt > mid) {
          wt = weights[i];
          cnt++;
        }
      }
      cnt++;
      if (cnt <= days) {
        ans = mid;
        high = mid - 1;
      }
      else low = mid + 1;
    }
    return ans;
  }
};

int main() {



  return 0;
}