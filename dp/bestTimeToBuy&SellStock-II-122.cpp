#include <iostream>
using namespace std;

class Solution {
public:
  int f(int i, bool canBuy, vector<int>& prices, int n, vector<vector<int>>& dp) {
    if (i == n) return 0;

    if (dp[i][canBuy] != -1) return dp[i][canBuy];

    if (canBuy) {
      int buy = -prices[i] + f(i + 1, 0, prices, n, dp);
      int notBuy = 0 + f(i + 1, 1, prices, n, dp);
      return dp[i][canBuy] = max(buy, notBuy);
    }
    else {
      int sell = prices[i] + f(i + 1, 1, prices, n, dp);
      int notSell = 0 + f(i + 1, 0, prices, n, dp);
      return dp[i][canBuy] = max(sell, notSell);
    }
  }
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    // vector<vector<int>> dp(n,vector<int>(2,-1));
    // return f(0,1,prices,n,dp);

    // vector<vector<int>> dp(n+1,vector<int>(2,0));
    // for(int i = n-1; i>=0; i--){
    //     for(int canBuy = 0; canBuy<=1; canBuy++){
    //         if(canBuy){
    //             int buy = -prices[i] + dp[i+1][0];
    //             int notBuy = 0 + dp[i+1][1];
    //             dp[i][canBuy] = max(buy,notBuy);
    //         }else{
    //             int sell = prices[i] + dp[i+1][1];
    //             int notSell = 0 + dp[i+1][0];
    //             dp[i][canBuy] = max(sell,notSell);
    //         }
    //     }
    // }
    // return dp[0][1];

    // vector<int> prev(2,0), curr(2,0);
    // for(int i = n-1; i>=0; i--){
    //     for(int canBuy = 0; canBuy<=1; canBuy++){
    //         int profit = 0;
    //         if(canBuy){
    //             // int buy = -prices[i] + prev[0];
    //             // int notBuy = 0 + prev[1];
    //             // curr[canBuy] = max(buy,notBuy);
    //             profit = max(-prices[i] + prev[0], prev[1]);
    //         }else{
    //             // int sell = prices[i] + prev[1];
    //             // int notSell = 0 + prev[0];
    //             // curr[canBuy] = max(sell,notSell);
    //             profit = max(prices[i] + prev[1],prev[0]);
    //         }
    //         curr[canBuy] = profit;
    //     }
    //     prev = curr;
    // }
    // return prev[1];

    // int prevBuy, prevNotBuy, currBuy, currNotBuy;
    // prevBuy = prevNotBuy = 0;

    // for(int i = n-1; i>=0; i--){
    //     currBuy = max(-prices[i] + prevNotBuy, prevBuy);
    //     currNotBuy = max(prices[i] + prevBuy,prevNotBuy);
    //     prevBuy = currBuy;
    //     prevNotBuy = currNotBuy;
    // }
    // return currBuy;

    int profit = 0;
    for (int i = 1; i < n; i++) {
      if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
    }
    return profit;

  }
};
int main() {



  return 0;
}