#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_map <int, int> umap;
    for (auto num : nums) {
      umap[num]++;
      if (umap[num] > 1) {
        return true;
      }
    }
    return false;
  }
};

int main() {



  return 0;
}