#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    int minCost = INT_MAX;
    int b = cost[cost.size() - 1];
    int a = cost[cost.size() - 2];
    for (int i = cost.size() - 3; i >= 0; i--) {
      minCost = cost[i] + min(a, b);
      b = a;
      a = minCost;
    }
    return min(a, b);
  }
};

int main() {



  return 0;
}