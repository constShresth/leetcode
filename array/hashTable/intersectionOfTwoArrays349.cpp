#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> umap;
    vector<int> result;
    for (int num : nums1) {
      if (umap.find(num) == umap.end()) {
        umap[num] = 1;
      }
    }
    for (int num : nums2) {
      if (umap.find(num) != umap.end()) {
        umap[num] = 0;
      }
    }
    for (auto pair : umap) {
      if (pair.second == 0) result.push_back(pair.first);
    }
    return result;
  }
};

int main() {



  return 0;
}