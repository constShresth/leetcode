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
    int a = nums[0];
    int b = nums[1];
    int c = nums[2] + a;
    for (int i = 3; i < nums.size(); i++) {
      int temp = nums[i] + max(a, b);
      a = b;
      b = c;
      c = temp;
    }
    return max(b, c);
  }
};

int main() {



  return 0;
}