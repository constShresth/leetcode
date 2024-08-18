#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    // int currMax = 0;
    // int prevMax = 0;
    // for(auto num:nums){
    //     int temp = currMax;
    //     currMax = max(prevMax+num, currMax);
    //     prevMax = temp;
    // }
    // return currMax;
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return max(nums[0], nums[1]);
    int c = nums[nums.size() - 1];
    int b = nums[nums.size() - 2];
    int a = nums[nums.size() - 3] + c;
    for (int i = nums.size() - 4; i >= 0; i--) {
      int temp = nums[i] + max(b, c);
      c = b;
      b = a;
      a = temp;
    }
    return max(a, b);
  }
};

int main() {



  return 0;
}