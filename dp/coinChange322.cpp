#include <iostream>
using namespace std;

class Solution {
public:
  int f(int i, int target, vector<int>& coins, vector<vector<int>>& dp) {
    if (i == 0) {
      if (target % coins[i] == 0) return target / coins[i];
      else return 1e5;
    }
    if (dp[i][target] != -1) return dp[i][target];

    int notTake = f(i - 1, target, coins, dp);
    int take = INT_MAX;
    if (coins[i] <= target) {
      take = 1 + f(i, target - coins[i], coins, dp);
    }
    return dp[i][target] = min(take, notTake);
  }
  int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> prev(amount + 1, 0);
    vector<int> curr(amount + 1, 0);

    for (int target = 0; target <= amount; target++) {
      if (target % coins[0] == 0) prev[target] = target / coins[0];
      else prev[target] = 1e5;
    }
    for (int i = 1; i < n; i++) {
      for (int target = 0; target <= amount; target++) {
        int notTake = prev[target];
        int take = INT_MAX;
        if (coins[i] <= target) {
          take = 1 + curr[target - coins[i]];
        }
        curr[target] = min(take, notTake);
      }
      prev = curr;
    }
    int ans = prev[amount];
    if (ans > 1e4) return -1;
    return ans;


    // vector<vector<int>> dp(n,vector<int>(amount+1,0));
    // for(int target = 0; target<=amount; target++) {
    //     if(target%coins[0]==0) dp[0][target] = target/coins[0];
    //     else dp[0][target] = 1e5;
    // }
    // for(int i = 1; i<n; i++){
    //     for(int target = 0; target<=amount; target++){
    //         int notTake = dp[i-1][target];
    //         int take = INT_MAX;
    //         if(coins[i]<=target){
    //             take = 1 + dp[i][target-coins[i]];
    //         }
    //         dp[i][target] = min(take,notTake);
    //     }
    // }
    // int ans = dp[n-1][amount];
    // if(ans>1e4) return -1;
    // return ans;
    // vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    // int ans = f(n-1,amount,coins,dp);
    // if(ans>1e4) return -1;
    // return ans;
  }
};

int main() {



  return 0;
}