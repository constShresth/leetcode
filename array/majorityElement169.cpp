#include <iostream>
using namespace std;

class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int majority = 0;
    int cnt = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (cnt == 0) {
        cnt = 1;
        majority = nums[i];
      }
      else if (nums[i] == majority) cnt++;
      else cnt--;
    }
    return majority;
    // since it always exists o/w we would have calculated & checked count;
    // voting algorithm



    // sort(nums.begin(), nums.end());
    // int freq = 1;
    // int maxFreq = 1;
    // int result = nums[0];
    // int i = 1;
    // while (i < nums.size()) {
    //   while (i < nums.size() && nums[i] == nums[i - 1]) {
    //     freq++;
    //     i++;
    //   }
    //   if (freq > maxFreq) {
    //     result = nums[i - 1];
    //     maxFreq = freq;
    //     freq = 1;
    //   }
    //   i++;
    // }
    // return result;
  }
};

int main() {



  return 0;
}