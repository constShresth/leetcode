#include <iostream>
using namespace std;

class Solution {
public:
  int binarySearch(vector<int>& nums, int target, int left, int right, int prevMid) {
    int res = nums.size();
    while (left <= right) {
      int mid = left + ((right - left) / 2);
      if (nums[mid] >= target) {
        res = mid;
        right = mid - 1;
      }
      else {
        left = mid + 1;
      }
    }
    return res;
  }
  int searchInsert(vector<int>& nums, int target) {
    return binarySearch(nums, target, 0, nums.size() - 1, 0);
  }
};

int main() {



  return 0;
}