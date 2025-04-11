#include <iostream>
using namespace std;

class Solution {
public:
  int minOperations(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++) {
      if (nums[i] < k) return -1;
      if (nums[i] > k) umap[nums[i]]++;
    }
    return umap.size();
  }
};

int main() {



  return 0;
}