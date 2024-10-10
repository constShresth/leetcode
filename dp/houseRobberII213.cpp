#include <iostream>
using namespace std;

class Solution {
public:
  int robI(vector<int>& nums) {
    int n = nums.size();
    int prev = 0;
    int prev2 = 0;
    for (int i = 0; i < n; i++) {
      int pick = nums[i] + prev2;
      int notPick = prev;
      int curr = max(pick, notPick);
      prev2 = prev;
      prev = curr;
    }
    return prev;
  }
  int rob(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    vector<int> first(nums.begin() + 1, nums.end());
    vector<int> second(nums.begin(), nums.end() - 1);
    return max(robI(first), robI(second));
  }
};

int main() {



  return 0;
}