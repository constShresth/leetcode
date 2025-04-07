#include <iostream>
using namespace std;

class Solution {
public:
  int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (mid == 0 || mid == n - 1) return nums[mid];
      if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return nums[mid];
      if (mid % 2 == 0) {
        if (nums[mid] == nums[mid + 1]) {
          low = mid + 1;
        }
        else if (nums[mid] == nums[mid - 1]) {
          high = mid - 1;
        }
      }
      else {
        if (nums[mid] == nums[mid + 1]) {
          high = mid - 1;
        }
        else if (nums[mid] == nums[mid - 1]) {
          low = mid + 1;
        }
      }
    }
    return -1;

    // if (n == 1) return nums[0];
    // for (int i = 0; i < n; i++) {
    //   if (i == 0) {
    //     if (nums[i] != nums[i + 1]) return nums[i];
    //   }
    //   else if (i == n - 1) {
    //     if (nums[i] != nums[i - 1]) return nums[i];
    //   }
    //   else {
    //     if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1]) return nums[i];
    //   }
    // }
    // return -1;
  }
};

int main() {



  return 0;
}