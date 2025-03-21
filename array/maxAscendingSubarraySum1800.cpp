#include <iostream>
using namespace std;

class Solution {
public:
  int maxAscendingSum(vector<int>& nums) {
    int n = nums.size();
    int maxSum = 0;
    int i = 0;
    int sum = 0;
    while (i < n) {
      if (i == 0 || nums[i] > nums[i - 1]) {
        sum += nums[i];
      }
      else {
        sum = nums[i];
      }
      maxSum = max(maxSum, sum);
      i++;
    }
    return maxSum;
    // o(n)

    // for (int i = 0; i < n; i++) {
    //   int sum = 0;
    //   for (int j = i; j < n; j++) {
    //     if (j == i || nums[j] > nums[j - 1]) {
    //       sum += nums[j];
    //       maxSum = max(maxSum, sum);
    //     }
    //     else break;
    //   }
    // }
    // return maxSum;
  }
};

int main() {



  return 0;
}