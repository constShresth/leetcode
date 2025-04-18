#include <iostream>
using namespace std;

class Solution {
public:
  int countPairs(vector<int>& nums, int k) {
    int n = nums.size();
    int cnt = 0;
    unordered_map<int, vector<int>> umap;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < umap[nums[i]].size(); j++) {
        if (i * umap[nums[i]][j] % k == 0) cnt++;
      }
      umap[nums[i]].push_back(i);
    }
    return cnt;

    // for(int i = 0; i<n; i++){
    //     for(int j = i+1; j<n; j++){
    //         if((nums[i]==nums[j]) && ((i*j)%k == 0)) cnt++;
    //     }
    // }
    // return cnt;
  }
};

int main() {



  return 0;
}