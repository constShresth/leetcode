#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  double findMaxAverage(vector<int>& nums, int k) {
    double res = INT_MIN;
    double sum = 0;
    int i = 1;
    int j = k;
    for (int i = 0; i < k; i++) {
      sum += nums[i];
    }
    res = sum;
    while (j < nums.size()) {
      sum = sum - nums[i - 1] + nums[j];
      res = max(res, sum);
      j++;
      i++;
    }
    return res / k;
  }
};

int main() {



  return 0;
}