#include <iostream>
using namespace std;

class Solution {
public:
  int findJumps(int pos, vector<int>& nums, vector<int>& dp) {
    if (pos >= nums.size() - 1) return 0;
    if (dp[pos] != -1) {
      return (dp[pos] == INT_MAX) ? INT_MAX : dp[pos];
    };

    int jump = INT_MAX;
    for (int i = 1; i <= nums[pos]; i++) {
      int steps = findJumps(pos + i, nums, dp);
      jump = min(jump, steps);
    }
    if (jump == INT_MAX) return dp[pos] = INT_MAX;

    return dp[pos] = jump + 1;
  }
  int jump(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 0;
    int l = 0;
    int r = 0;
    int jumps = 0;
    while (r < n - 1) {
      int farthest = 0;
      for (int i = l; i <= r; i++) {
        farthest = max(farthest, i + nums[i]);
      }
      l = r + 1;
      r = farthest;
      jumps++;
      //tc-> O(n)
      //sc-> O(1)
    }
    return jumps;
    // vector<int> dp(nums.size(), INT_MAX);
    // dp[n-1] = 0;
    // // findJumps(0, nums, dp);
    // for(int i = n-2; i>=0; i--){
    //     for(int j = nums[i]; j>=1; j--){
    //         if(i+j>=n-1){
    //             dp[i] = 1;
    //             break;
    //         }else{
    //             (dp[i+j]==INT_MAX) ?
    //             dp[i] = min(dp[i], INT_MAX) :
    //             dp[i] = min(dp[i], dp[i+j] + 1);
    //         }
    //     }
    // }
    // return dp[0];
  }
};

int main() {



  return 0;
}