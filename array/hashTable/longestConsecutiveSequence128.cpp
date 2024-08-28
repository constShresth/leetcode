#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_map <int, int> umap;
    int result = 0;
    sort(nums.begin(), nums.end());
    for (auto num : nums) {
      if (umap.find(num - 1) != umap.end()) {
        umap[num] = umap[num - 1] + 1;
        umap.erase(num - 1);
      }
      else if (umap.find(num) == umap.end()) {
        umap[num] = 1;
      }
    }
    for (auto pair : umap) {
      result = max(result, pair.second);
    }
    return result;
  }
};

int main() {



  return 0;
}