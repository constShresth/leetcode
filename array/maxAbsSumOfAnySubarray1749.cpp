#include <iostream>
using namespace std;

class Solution {
public:
  int maxAbsoluteSum(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++) {
      sum += nums[i];

      if (sum > maxi) {
        maxi = sum;
      }
      if (sum < 0) sum = 0;
    }

    int maxi2 = INT_MAX;
    sum = 0;
    for (int i = 0; i < n; i++) {
      sum += nums[i];

      if (sum < maxi2) {
        maxi2 = sum;
      }
      if (sum > 0) sum = 0;
    }
    return max(maxi, abs(maxi2));
  }
};

int main() {



  return 0;
}