#include <iostream>
using namespace std;

class Solution {
public:
  int f(int i, int canBuy, int tx, vector<int>& prices, int n, vector<vector<vector<int>>>& dp) {
    if (i == n || tx == 2) return 0;

    if (dp[i][canBuy][tx] != -1) return dp[i][canBuy][tx];

    if (canBuy) {
      int buy = -prices[i] + f(i + 1, 0, tx, prices, n, dp);
      int notBuy = 0 + f(i + 1, 1, tx, prices, n, dp);
      return dp[i][canBuy][tx] = max(buy, notBuy);
    }
    else {
      int sell = prices[i] + f(i + 1, 1, tx + 1, prices, n, dp);
      int notSell = 0 + f(i + 1, 0, tx, prices, n, dp);
      return dp[i][canBuy][tx] = max(sell, notSell);
    }
  }
  int f2(int i, int tx, vector<int>& prices, int n, vector<vector<int>>& dp) {
    if (i == n || tx == 4) return 0;

    if (dp[i][tx] != -1) return dp[i][tx];

    if (tx % 2 == 0) {
      int buy = -prices[i] + f2(i + 1, tx + 1, prices, n, dp);
      int notBuy = 0 + f2(i + 1, tx, prices, n, dp);
      return dp[i][tx] = max(buy, notBuy);
    }
    else {
      int sell = prices[i] + f2(i + 1, tx + 1, prices, n, dp);
      int notSell = 0 + f2(i + 1, tx, prices, n, dp);
      return dp[i][tx] = max(sell, notSell);
    }
  }

  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
    // return f(0,1,0,prices,n,dp);
    // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    // for(int i = n-1; i>=0; i--){
    //     for(int canBuy=0; canBuy<=1; canBuy++){
    //         for(int tx=1; tx>=0; tx--){
    //             if(canBuy){
    //                 int buy = -prices[i] + dp[i+1][0][tx];
    //                 int notBuy = 0 + dp[i+1][1][tx];
    //                 dp[i][canBuy][tx] = max(buy,notBuy);
    //             }else{
    //                 int sell = prices[i] + dp[i+1][1][tx+1];
    //                 int notSell = 0 + dp[i+1][0][tx];
    //                 dp[i][canBuy][tx] = max(sell,notSell);
    //             }
    //         }
    //     }
    // }

    // return dp[0][1][0];

    // vector<vector<int>> dp(n,vector<int>(4,-1));
    // return f2(0,0,prices,n,dp);

    // vector<vector<int>> dp(n+1,vector<int>(5,0));
    // for(int i = n-1; i>=0; i--){
    //     for(int tx=3; tx>=0; tx--){
    //         if(tx%2==0){
    //             int buy = -prices[i] + dp[i+1][tx+1];
    //             int notBuy = 0 + dp[i+1][tx];
    //             dp[i][tx] = max(buy,notBuy);
    //         }else{
    //             int sell = prices[i] + dp[i+1][tx+1];
    //             int notSell = 0 + dp[i+1][tx];
    //             dp[i][tx] = max(sell,notSell);
    //         }
    //     }
    // }
    // return dp[0][0];

    vector<int> prev(5, 0), curr(5, 0);
    for (int i = n - 1; i >= 0; i--) {
      for (int tx = 3; tx >= 0; tx--) {
        if (tx % 2 == 0) {
          int buy = -prices[i] + prev[tx + 1];
          int notBuy = 0 + prev[tx];
          curr[tx] = max(buy, notBuy);
        }
        else {
          int sell = prices[i] + prev[tx + 1];
          int notSell = 0 + prev[tx];
          curr[tx] = max(sell, notSell);
        }
      }
      prev = curr;
    }
    return prev[0];
  }
};

int main() {



  return 0;
}