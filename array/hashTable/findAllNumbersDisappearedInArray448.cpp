#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    unordered_map<int, int> umap;
    vector<int> result;
    for (auto num : nums) {
      umap[num]++;
    }
    for (int i = 1; i <= nums.size(); i++) {
      if (umap.find(i) == umap.end()) result.push_back(i);
    }
    return result;
  }
};

int main() {



  return 0;
}