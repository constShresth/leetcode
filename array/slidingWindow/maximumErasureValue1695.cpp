#include <iostream>
using namespace std;

class Solution {
public:
  int maximumUniqueSubarray(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = 0, res = 0, sum = 0;
    unordered_map<int, int> umap;
    while (r < n) {
      umap[nums[r]]++;
      sum += nums[r];
      while (umap[nums[r]] > 1) {
        umap[nums[l]]--;
        sum -= nums[l];
        l++;
      }
      res = max(res, sum);
      r++;
    }
    return res;
  }
};

int main() {



  return 0;
}