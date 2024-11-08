#include <iostream>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int maxProfit = 0;
    int lastBuy = prices[0];
    for (int i = 1; i < prices.size(); i++) {
      int profit = prices[i] - lastBuy;
      maxProfit = max(maxProfit, profit);
      lastBuy = min(lastBuy, prices[i]);
    }

    return maxProfit;
  }
};

int main() {



  return 0;
}