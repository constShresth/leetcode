#include <iostream>
using namespace std;

class Solution {
public:
  long long mod = 1e10 + 7;
  int f(int i, int tar, vector<int>& coins, vector<vector<int>>& dp) {
    if (i == 0) {
      if (tar % coins[i] == 0) return 1;
      else return 0;
    }
    if (dp[i][tar] != -1) return dp[i][tar];
    int notTake = f(i - 1, tar, coins, dp);
    int take = 0;
    if (coins[i] <= tar) {
      take = f(i, tar - coins[i], coins, dp);
    }
    return dp[i][tar] = take + notTake;
  }
  int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<long long>> dp(n, vector<long long>(amount + 1, 0));
    for (int i = 0; i < n; i++) dp[i][0] = 1;
    for (int tar = 0; tar <= amount; tar++) {
      if (tar % coins[0] == 0) dp[0][tar] = 1;
    }
    for (int i = 1; i < n; i++) {
      for (int tar = 0; tar <= amount; tar++) {
        long long notTake = dp[i - 1][tar];
        long long take = 0;
        if (coins[i] <= tar) {
          take = dp[i][tar - coins[i]];
        }
        dp[i][tar] = (take + notTake) % mod;
      }
    }
    return dp[n - 1][amount];
    // vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    // return f(n-1,amount,coins,dp);

  }
};

int main() {



  return 0;
}