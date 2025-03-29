#include <iostream>
using namespace std;

class Solution {
public:
  void sortColors(vector<int>& nums) {
    // dutch flag algo
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) {
      if (nums[mid] == 0) {
        swap(nums[low], nums[mid]);
        low++;
        mid++;
      }
      else if (nums[mid] == 1) mid++;
      else if (nums[mid] == 2) {
        swap(nums[mid], nums[high]);
        high--;
      }
    }


    // int n = nums.size();
    // int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    // for (auto it : nums) {
    //   if (it == 0) cnt0++;
    //   else if (it == 1) cnt1++;
    //   else cnt2++;
    // }
    // for (int i = 0; i < n; i++) {
    //   if (cnt0 > 0) {
    //     nums[i] = 0;
    //     cnt0--;
    //   }
    //   else if (cnt1 > 0) {
    //     nums[i] = 1;
    //     cnt1--;
    //   }
    //   else if (cnt2 > 0) {
    //     nums[i] = 2;
    //     cnt2--;
    //   }
    // }
  }
};

int main() {



  return 0;
}