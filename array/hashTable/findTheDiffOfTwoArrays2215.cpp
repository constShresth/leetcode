#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> res(2);
    unordered_map <int, int> map;
    for (const auto num : nums1) {
      if (map.find(num) == map.end()) {
        map[num] = 1;
      }

    }
    for (const auto num : nums2) {
      if (map.find(num) == map.end()) {
        map[num] = 2;
      }      
else {
        if (map[num] < 2) {
          map[num]--;
        }
      }
    }
    for (const auto pair : map) {
      if (pair.second == 1) {
        res[0].push_back(pair.first);
      }
      else if (pair.second == 2) {
        res[1].push_back(pair.first);
      }
    }
    return res;
  }
};

int main() {



  return 0;
}