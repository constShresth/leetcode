#include <iostream>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<int> prev(2, 0), curr(2, 0);
    for (int i = n - 1; i >= 0; i--) {
      for (int canBuy = 0; canBuy <= 1; canBuy++) {
        int profit = 0;
        if (canBuy) {
          profit = max(-prices[i] + prev[0], prev[1]);
        }
        else profit = max(prices[i] - fee + prev[1], prev[0]);
        curr[canBuy] = profit;
      }
      prev = curr;
    }
    return prev[1];
  }
};

int main() {



  return 0;
}