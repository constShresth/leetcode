#include <iostream>
using namespace std;

class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> umap;
    int n = nums.size();
    int sum = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
      sum += nums[i];
      if (sum == k) res++;
      int rem = sum - k;
      if (umap.find(rem) != umap.end()) {
        res += umap[rem];
      }

      umap[sum]++;
    }
    return res;
  }
};

int main() {



  return 0;
}