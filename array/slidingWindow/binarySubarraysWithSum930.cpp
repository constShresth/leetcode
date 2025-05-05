#include <iostream>
using namespace std;

class Solution {
private:
  int numSubarraysWithSumLessThanOrEqual(vector<int>& nums, int goal) {
    if (goal < 0) return 0;
    int n = nums.size();
    int l = 0, r = 0, sum = 0, ans = 0;
    while (r < n) {
      sum += nums[r];
      while (sum > goal) {
        sum -= nums[l];
        l++;
      }
      ans += (r - l + 1);
      r++;
    }
    return ans;
  }
public:
  int numSubarraysWithSum(vector<int>& nums, int goal) {
    return numSubarraysWithSumLessThanOrEqual(nums, goal) - numSubarraysWithSumLessThanOrEqual(nums, goal - 1);
    // unordered_map<int,int> umap;
    // int n = nums.size();
    // int sum = 0;
    // int res = 0;
    // for(int i = 0; i<n; i++){
    //     sum += nums[i];
    //     if(sum == goal) res++;
    //     int rem = sum - goal;
    //     if(umap.find(rem) != umap.end()){
    //         res += umap[rem];
    //     }
    //     umap[sum]++;
    // }
    // return res;

  }
};

int main() {



  return 0;
}