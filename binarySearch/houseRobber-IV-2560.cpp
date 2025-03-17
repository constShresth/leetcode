#include <iostream>
using namespace std;

class Solution {
private:
  int f(int i, vector<int>& nums, int count, vector<vector<int>>& dp) {
    if (count == 0) return 0;
    if (i == 0) {
      if (count == 1) return nums[i];
      else 1e9;
    };
    if (i < 0) return 1e9;

    if (dp[i][count] != -1) return dp[i][count];

    int pick = max(nums[i], f(i - 2, nums, count - 1, dp));
    int notPick = f(i - 1, nums, count, dp);

    return dp[i][count] = min(pick, notPick);
  }
  bool isValid(int capability, vector<int>& nums, int k) {
    int i = 0;
    int count = 0;
    while (i < nums.size()) {
      if (nums[i] <= capability) {
        count++;
        i += 2;
      }
      else {
        i++;
      }
      if (count == k) {
        return true;
      }
    }
    return false;
  }
public:
  int minCapability(vector<int>& nums, int k) {
    int l = *min_element(nums.begin(), nums.end());
    int r = *max_element(nums.begin(), nums.end());
    int res = 0;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (isValid(m, nums, k)) {
        res = m;
        r = m - 1;
      }
      else {
        l = m + 1;
      }
    }
    return res;

    // int n = nums.size();
    // vector<vector<int>> dp(n,vector<int>(k+1,-1));
    // return f(n-1,nums,k,dp);
    // o(n*k) tle
    

  }
};

int main() {



  return 0;
}