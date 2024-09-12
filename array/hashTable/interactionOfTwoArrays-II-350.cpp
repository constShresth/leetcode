#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    // vector<int> result;
    // int i = 0;
    // int j = 0;
    // sort(nums1.begin(), nums1.end());
    // sort(nums2.begin(), nums2.end());
    // while (i < nums1.size() && j < nums2.size()) {
    //   while (i < nums1.size() && j < nums2.size() && nums1[i] < nums2[j]) i++;
    //   while (i < nums1.size() && j<nums2.size() && nums1[i]>nums2[j]) j++;
    //   while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
    //     result.push_back(nums1[i]);
    //     i++;
    //     j++;
    //   }
    // }
    // return result;

    unordered_map <int, int> umap;
    vector<int> result;
    for (auto num : nums1)umap[num]++;
    for (auto num : nums2) {
      if (umap.find(num) != umap.end() && umap[num] != 0) {
        umap[num]--;
        result.push_back(num);
      }
    };
    return result;
  }
};

int main() {



  return 0;
}