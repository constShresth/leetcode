#include <iostream>
using namespace std;

class Solution {
public:
  int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1), cnt(n, 1);
    int len = 1;
    for (int i = 0; i < n; i++) {
      for (int prev = 0; prev < i; prev++) {
        if (nums[i] > nums[prev] && 1 + dp[prev] > dp[i]) {
          dp[i] = 1 + dp[prev];
          cnt[i] = cnt[prev];
        }
        else if (nums[i] > nums[prev] && 1 + dp[prev] == dp[i]) {
          cnt[i] += cnt[prev];
        }
      }
      len = max(len, dp[i]);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
      if (dp[i] == len) count += cnt[i];
    }
    return count;
  }
};

int main() {



  return 0;
}