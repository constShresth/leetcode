#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int res = 1;
    unordered_set<int> s;
    for (auto it : nums) s.insert(it);
    for (auto it : s) {
      if (s.find(it - 1) == s.end()) {
        int cnt = 1;
        while (s.find(it + 1) != s.end()) {
          cnt++;
          it = it + 1;
        }
        res = max(res, cnt);
      }
    }
    return res;


    // int n = nums.size();
    // if (n == 0) return 0;
    // int res = 1;
    // sort(nums.begin(), nums.end());
    // int cnt = 1;
    // for (int i = 1; i < n; i++) {
    //   if (nums[i] == nums[i - 1]) continue;
    //   if (nums[i] == nums[i - 1] + 1) {
    //     cnt++;
    //     res = max(res, cnt);
    //   }
    //   else {
    //     cnt = 1;
    //   }
    // }
    // return res;

    // unordered_map <int, int> umap;
    // int result = 0;
    // sort(nums.begin(), nums.end());
    // for (auto num : nums) {
    //   if (umap.find(num - 1) != umap.end()) {
    //     umap[num] = umap[num - 1] + 1;
    //     umap.erase(num - 1);
    //   }
    //   else if (umap.find(num) == umap.end()) {
    //     umap[num] = 1;
    //   }
    // }
    // for (auto pair : umap) {
    //   result = max(result, pair.second);
    // }
    // return result;
  }
};

int main() {



  return 0;
}