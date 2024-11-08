#include <iostream>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> prev2(2, 0), prev1(2, 0), curr(2, 0);
    for (int i = n - 1; i >= 0; i--) {
      for (int canBuy = 0; canBuy <= 1; canBuy++) {
        int profit = 0;
        if (canBuy) {
          profit = max(-prices[i] + prev1[0], prev1[1]);
        }
        else profit = max(prices[i] + prev2[1], prev1[0]);
        curr[canBuy] = profit;
      }
      prev2 = prev1;
      prev1 = curr;
    }

    return prev1[1];


    // vector<vector<int>> dp(n+2,vector<int>(2,0));
    // for(int i = n-1; i>=0; i--){
    //     for(int canBuy = 0; canBuy<=1; canBuy++){
    //         int profit = 0;
    //         if(canBuy){
    //             profit = max(-prices[i]+dp[i+1][0], dp[i+1][1]);
    //         }else profit = max(prices[i]+dp[i+2][1], dp[i+1][0]);
    //         dp[i][canBuy] = profit;
    //     }
    // }

    // return dp[0][1];
  }
};

int main() {



  return 0;
}