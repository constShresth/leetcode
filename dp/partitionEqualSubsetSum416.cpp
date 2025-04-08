#include <iostream>
#include <numeric>
using namespace std;

class Solution {
private:
  bool subsetSumToK(int n, int k, vector<int>& nums) {

    vector<int> prev(k + 1, false), curr(k + 1, false);
    prev[0] = curr[0] = true;
    if (nums[0] <= k) prev[nums[0]] = true;

    for (int i = 1; i < n; i++) {
      for (int tar = 1; tar <= k; tar++) {
        bool notPick = prev[tar];
        bool pick = false;
        if (nums[i] <= tar) pick = prev[tar - nums[i]];
        curr[tar] = pick || notPick;
      }
      prev = curr;
    }
    return prev[k];
  }
public:
  bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if (totalSum % 2 != 0) return false;
    int k = totalSum / 2;
    return subsetSumToK(n, k, nums);
  }
};

int main() {



  return 0;
}