#include <iostream>
using namespace std;

class Solution {
private:
  int subarraysWithLessOrEqualKDistinct(vector<int>& nums, int k) {
    int n = nums.size();
    int l = 0, r = 0, ans = 0;
    unordered_map<int, int> umap;
    while (r < n) {
      umap[nums[r]]++;
      while (umap.size() > k) {
        umap[nums[l]]--;
        if (umap[nums[l]] == 0) umap.erase(nums[l]);
        l++;
      }
      ans += (r - l + 1);
      r++;
    }
    return ans;
  }
public:
  int subarraysWithKDistinct(vector<int>& nums, int k) {
    int a = subarraysWithLessOrEqualKDistinct(nums, k);
    int b = subarraysWithLessOrEqualKDistinct(nums, k - 1);
    return a - b;
  }
};

int main() {



  return 0;
}