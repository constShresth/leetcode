#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
    if (nums.size() < 3) return false;
    int first = INT_MAX;
    int second = INT_MAX;
    for (int num : nums) {
      if (num <= first) first = num;
      else if (num <= second) second = num;
      else return true;
    }
    return false;
    // if (nums.size() < 3) return false;
    // int n = nums.size();
    // vector<int> leftMin(n);
    // vector<int> rightMax(n);
    // leftMin[0] = nums[0];
    // rightMax[n - 1] = nums[n - 1];
    // for (int i = 1; i < n; i++) {
    //   leftMin[i] = min(leftMin[i - 1], nums[i]);
    // }
    // for (int i = n - 2; i >= 0; i--) {
    //   rightMax[i] = max(rightMax[i + 1], nums[i]);
    // }
    // for (int i = 0; i < n; i++) {
    //   if (nums[i] > leftMin[i] && nums[i] < rightMax[i]) return true;
    // }
    // return false;
  }
};

int main() {



  return 0;
}