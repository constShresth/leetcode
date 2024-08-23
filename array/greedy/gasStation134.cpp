#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  // bool checkCircuit(int index, int i, int remainingGas, int n, vector<int>& gas, vector<int>& cost) {
  //   if (i == index) return true;
  //   if (gas[i] + remainingGas >= cost[i]) {
  //     return checkCircuit(index, (i + 1) % n, gas[i] + remainingGas - cost[i], n, gas, cost);
  //   }
  //   else {
  //     return false;
  //   }
  // }
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int totalTank = 0, currTank = 0, start = 0;
    for (int i = 0; i < cost.size(); i++) {
      totalTank += gas[i] - cost[i];
      currTank += gas[i] - cost[i];
      if (currTank < 0) {
        currTank = 0;
        start = i + 1;
      }
    }
    return (totalTank < 0) ? -1 : start;

    //recursive approach -> gives TLE for large inputs
    // int n = gas.size();
    // for (int i = 0; i < cost.size(); i++) {
    //   if (gas[i] >= cost[i]) {
    //     if (checkCircuit(i, (i + 1) % n, gas[i] - cost[i], n, gas, cost)) return i;
    //   }
    // }
    // return -1;
  }
};

int main() {



  return 0;
}