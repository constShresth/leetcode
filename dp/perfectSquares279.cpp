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
  int solve(int n, vector<int>& dp) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];
    int ans = n;
    for (int i = 1; i * i <= n; i++) {
      int temp = i * i;
      ans = min(ans, 1 + solve(n - temp, dp));
    }
    return dp[n] = ans;
  }
  int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int j = 1; j <= n; j++) {
      for (int i = 1; i * i <= n; i++) {
        int temp = i * i;
        if (j - temp >= 0)
          dp[j] = min(dp[j], 1 + dp[j - temp]);
      }
    }
    return dp[n];
    // vector<int> dp(n+1,-1);
    // return solve(n,dp);

    //tle
    // vector<int> coins;
    // for(int i = 1; i<=n/pow(n,1/2); i++){
    //     coins.push_back(i*i);
    // }
    // vector<int> prev(n+1,0), curr(n+1,0);

    // for(int target = 0; target<=n; target++) {
    //     if(target%coins[0]==0) prev[target] = target/coins[0];
    //     else prev[target] = 1e5;
    // }
    // for(int i = 1; i<n; i++){
    //     for(int target = 0; target<=n; target++){
    //         int notTake = prev[target];
    //         int take = INT_MAX;
    //         if(coins[i]<=target){
    //             take = 1 + curr[target-coins[i]];
    //         }
    //         curr[target] = min(take,notTake);
    //     }
    //     prev = curr;
    // }
    // return prev[n];
    // vector<vector<int>> dp(n,vector<int>(n+1,-1));
    // return f(coins.size()-1,n,coins,dp);

  }
};

int main() {



  return 0;
}