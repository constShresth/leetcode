#include <iostream>
using namespace std;

class Solution {
public:
  int countCompleteSubarrays(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++) umap[nums[i]]++;
    int distinct = umap.size();
    umap.clear();
    int l = 0, r = 0, res = 0;
    while (r < n) {
      umap[nums[r]]++;
      while (umap.size() == distinct) {
        res += (n - r);
        umap[nums[l]]--;
        if (umap[nums[l]] == 0) umap.erase(nums[l]);
        l++;
      }
      r++;
    }
    return res;
  }
};

int main() {



  return 0;
}