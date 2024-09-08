#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int longestOnes(vector<int>& nums, int k) {
    int left = 0;
    int right = 0;
    int countZero = 0;
    int res = 0;
    while (right < nums.size()) {
      if (nums[right] == 0) countZero++;
      // while (countZero > k) {
      //   if (nums[left] == 0) countZero--;
      //   left++;
      // }
      if (countZero <= k) res = max(res, right - left + 1);
      else {
        if (nums[left] == 0) countZero--;
        left++;
      };
      right++;
    }
    return res;
  }
};

int main() {



  return 0;
}