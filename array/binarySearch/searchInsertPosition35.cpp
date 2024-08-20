#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int binarySearch(vector<int>& nums, int target, int left, int right, int prevMid) {
    if (left > right) {
      if (target < nums[prevMid]) {
        return prevMid;
      }
      else {
        return prevMid + 1;
      }
    };
    int mid = left + ((right - left) / 2);
    if (target == nums[mid]) {
      return mid;
    }
    else if (target < nums[mid]) {
      return binarySearch(nums, target, left, mid - 1, mid);
    }
    else {
      return binarySearch(nums, target, mid + 1, right, mid);
    }
  }
  int searchInsert(vector<int>& nums, int target) {
    return binarySearch(nums, target, 0, nums.size() - 1, 0);
  }
};

int main() {



  return 0;
}