#include <iostream>
using namespace std;

class Solution {
private:
  // vector<int> f(int i, int prev, vector<int> &nums,unordered_map<pair<int,int>,vector<int>> dp){
      // memoisation is difficult
  //     if(i==nums.size()) return {};

  //     if(dp.find({i,prev}) != dp.end()) return dp[i][prev];

  //     vector<int> take;
  //     vector<int> notTake;
  //     if(prev==-1 || nums[i] % nums[prev] == 0){
  //         take.push_back(nums[i]);
  //         vector<int> res1 = f(i+1,i,nums,dp);
  //         take.insert(take.end(),res1.begin(),res1.end());
  //     }
  //     vector<int> res2 = f(i+1,prev,nums,dp);
  //     notTake.insert(notTake.end(),res2.begin(),res2.end());

  //     return dp[i][prev] = take.size() > notTake.size() ? take : notTake;

  // }
public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> dp(n, 1);
    vector<int> hash(n);
    int resIndex = 0;
    int res = 0;
    for (int i = 0; i < n; i++) hash[i] = i;
    for (int i = 1; i < n; i++) {
      for (int prev = 0; prev < i; prev++) {
        if ((nums[i] % nums[prev] == 0) && (dp[prev] + 1 > dp[i])) {
          // dp[i] = max(dp[i],dp[prev] + 1);
          dp[i] = dp[prev] + 1;
          hash[i] = prev;
        }
      }
      if (dp[i] > res) {
        res = dp[i];
        resIndex = i;
      }
    }
    vector<int> ans;
    while (hash[resIndex] != resIndex) {
      ans.push_back(nums[resIndex]);
      resIndex = hash[resIndex];
    }
    ans.push_back(nums[resIndex]);
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main() {



  return 0;
}