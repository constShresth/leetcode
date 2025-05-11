#include <iostream>
using namespace std;

class Solution {
  vector<int> dp;
  bool f(int ind, vector<int>& nums) {
    if (ind >= nums.size() - 1) return true;
    if (dp[ind] != -1) return dp[ind];
    for (int i = 1; i <= nums[ind]; i++) {
      if (f(ind + i, nums)) return dp[ind] = true;
    }
    return dp[ind] = false;
  }
public:
  bool canJump(vector<int>& nums) {
    int n = nums.size();
    int maxIndex = 0;
    for (int i = 0; i < n; i++) {
      if (i > maxIndex) return false;
      maxIndex = max(maxIndex, i + nums[i]);
      if (maxIndex >= n - 1) return true;
    }

    return true;
    // dp.resize(nums.size(),-1);
    // return f(0,nums);
    // o(n^2)
  }
};

int main() {



  return 0;
}