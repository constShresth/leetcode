#include <iostream>
using namespace std;

class Solution {
public:
  int minimumOperations(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    unordered_map<int, int> umap;
    for (int i = n - 1; i >= 0; i--) {
      umap[nums[i]]++;
      if (umap[nums[i]] > 1) {
        return (i / 3) + 1;
      }
    }
    return 0;
  }
};

int main() {



  return 0;
}