#include <iostream>
using namespace std;

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int xor1 = 0;
    int xor2 = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      xor1 = xor1 ^ i;
      xor2 = xor2 ^ nums[i];
    }
    xor1 = xor1 ^ n;
    return xor1 ^ xor2;
    // this is better because sum might lead to integer overflow.

    // int sum1 = 0;
    // for (int i = 0; i <= nums.size(); i++) {
    //   sum1 += i;
    // }
    // int sum2 = accumulate(nums.begin(), nums.end(), 0);
    // return sum1 - sum2;
  }
};

int main() {



  return 0;
}