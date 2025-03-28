#include <iostream>
using namespace std;
class Solution {
public:
  int minimumIndex(vector<int>& nums) {
    int n = nums.size();
    int majority;
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (count == 0) {
        majority = nums[i];
        count = 1;
      }
      else if (nums[i] == majority)count++;
      else count--;
    }
    count = 0;
    for (auto it : nums) if (it == majority) count++;
    int f = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] == majority) f++;
      if (f > (i + 1) / 2 && (count - f) > (n - (i + 1)) / 2) return i;
    }
    return -1;


    // unordered_map<int, int> umapL;
    // unordered_map<int, int> umap;

    // for (auto it : nums) {
    //   umap[it]++;
    // }


    // for (int i = 0; i < n; i++) {
    //   umapL[nums[i]]++;
    //   umap[nums[i]]--;
    //   if (umapL[nums[i]] > (i + 1) / 2 && umap[nums[i]] > (n - (i + 1)) / 2) {
    //     return i;
    //   }
    // }
    // return -1;


    // int dominant;
    // int freq = 0;
    // for (auto it : umap) {
    //   if (it.second > freq) {
    //     freq = it.second;
    //     dominant = it.first;
    //   }
    // }
    // int f = 0;
    // for (int i = 0; i < n; i++) {
    //   if (nums[i] == dominant) f++;
    //   if (f > (i + 1) / 2 && (freq - f) > (n - (i + 1)) / 2) {
    //     return i;
    //   }
    // }
    // return -1;
  }
};

int main() {



  return 0;
}