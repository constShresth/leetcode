#include <iostream>
using namespace std;

class Solution {
private:
  vector<int> dp;
  int f(int ind, vector<int>& nums) {
    if (ind >= nums.size() - 1) return 0;

    if (dp[ind] != -1) return dp[ind];

    int steps = INT_MAX - 1;
    for (int i = 1; i <= nums[ind]; i++) {
      steps = min(steps, 1 + f(ind + i, nums));
    }

    return dp[ind] = steps;
  }
public:
  int jump(vector<int>& nums) {
    int n = nums.size();
    int r = 0, l = 0, jumps = 0;
    while (r < n - 1) {
      int farthest = 0;
      for (int i = l; i <= r; i++) farthest = max(farthest, i + nums[i]);
      l = r + 1;
      r = farthest;
      jumps++;
    }
    //tc-> O(n)
    //sc-> O(1)
    return jumps;

    // dp.resize(nums.size(), -1);
    // return f(0,nums);

    // vector<int> dp(nums.size(), INT_MAX);
    // dp[n-1] = 0;
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