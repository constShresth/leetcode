#include <iostream>
using namespace std;

class Solution {
public:
  int findMin(vector<int>& nums) {
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      // if whole part is sorted
      // optional condition
      // code will run even without it
      if (nums[low] <= nums[high]) {
        ans = min(ans, nums[low]);
        break;
      }

      if (nums[low] <= nums[mid]) {
        ans = min(ans, nums[low]);
        low = mid + 1;
      }
      else {
        ans = nums[mid];
        high = mid - 1;
      }

      // consider ans = nums[0]
      // if (nums[mid] < ans) {
      //   ans = nums[mid];
      //   high = mid - 1;
      // }
      // else {
      //   low = mid + 1;
      // }
    }
    return ans;
  }
};

int main() {



  return 0;
}