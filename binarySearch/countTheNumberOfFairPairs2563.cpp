#include <iostream>
using namespace std;

class Solution {
public:
  long long countFairPairs(vector<int>& nums, int lower, int upper) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
      int low = lower - nums[i];
      int high = upper - nums[i];
      auto x = lower_bound(nums.begin() + i + 1, nums.end(), low);
      auto y = upper_bound(nums.begin() + i + 1, nums.end(), high);
      cnt += (y - x);
    }
    return cnt;

    // int cnt = 0;
    // for(int i = 0; i<n; i++){
    //     for(int j = i+1; j<n; j++){
    //         int sum = nums[i] + nums[j];
    //         if(lower <= sum && sum <= upper) cnt++;
    //     }
    // }
    // return cnt;
  }
};

int main() {



  return 0;
}