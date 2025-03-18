#include <iostream>
using namespace std;

class Solution {
public:
  bool divideArray(vector<int>& nums) {
    unordered_map<int, int> umap;
    int n = nums.size();
    for (auto it : nums) {
      umap[it]++;
    }
    for (auto it : umap) {
      if (it.second % 2 != 0) return false;
    }
    return true;
  }
};

int main() {



  return 0;
}