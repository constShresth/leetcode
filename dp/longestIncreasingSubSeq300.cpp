#include <iostream>
using namespace std;

class Solution {
public:
  int f(int i, int prev, vector<int>& nums, int n, vector<vector<int>>& dp) {
    if (i == n) return 0;

    if (dp[i][prev + 1] != -1) return dp[i][prev + 1];

    int notTake = 0 + f(i + 1, prev, nums, n, dp);
    int take = INT_MIN;
    if (prev == -1 || nums[i] > nums[prev]) {
      take = 1 + f(i + 1, i, nums, n, dp);
    }
    return dp[i][prev + 1] = max(take, notTake);
  }
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> res;
    res.push_back(nums[0]);
    for (int i = 1; i < n; i++) {
      if (nums[i] > res.back()) res.push_back(nums[i]);
      else {
        int index = lower_bound(res.begin(), res.end(), nums[i]) - res.begin();
        res[index] = nums[i];
      }
    }
    return res.size();

    // vector<vector<int>> dp(n,vector<int>(n+1,-1));
    // return f(0,-1,nums,n,dp);

    // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    // for(int i = n-1; i>=0; i--){
    //     for(int prev = i-1; prev>=-1; prev--){
    //         int notTake = 0 + dp[i+1][prev+1];
    //         int take = INT_MIN;
    //         if(prev==-1 || nums[i]>nums[prev]){
    //             take = 1 + dp[i+1][i+1];
    //         }
    //         dp[i][prev+1] = max(take,notTake);
    //     }
    // }
    // return dp[0][-1+1];

  }
};

int main() {



  return 0;
}