#include <iostream>
using namespace std;

class Solution {
public:
  int smallestDivisor(vector<int>& nums, int threshold) {
    int n = nums.size();

    int low = 1, high = INT_MIN;
    for (int i = 0; i < n; i++) {
      high = max(high, nums[i]);
    }
    int ans = -1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int sum = 0;
      for (int i = 0; i < n; i++) {
        sum += (nums[i] + mid - 1) / mid;
      }
      if (sum <= threshold) {
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