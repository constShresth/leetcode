#include <iostream>
using namespace std;

class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    int t = 2 * k;
    vector<int> prev(t + 1, 0), curr(t + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
      for (int tx = t - 1; tx >= 0; tx--) {
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