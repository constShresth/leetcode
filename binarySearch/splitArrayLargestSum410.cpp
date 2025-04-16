#include <iostream>
using namespace std;

class Solution {
private:
  int countSplits(vector<int>& nums, int maxi) {
    int n = nums.size();
    int cnt = 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (sum + nums[i] <= maxi) {
        sum += nums[i];
      }      
else {
        cnt++;
        sum = nums[i];
      }
    }
    return cnt;
  }
public:
  int splitArray(vector<int>& nums, int k) {
    int n = nums.size();
    int low = INT_MIN;
    int high = 0;
    for (int i = 0; i < n; i++) {
      low = max(low, nums[i]);
      high += nums[i];
    }
    int ans = -1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (countSplits(nums, mid) > k) {
        low = mid + 1;
      }
      else {
        ans = mid;
        high = mid - 1;
      }
    }
    return ans;
  }
};

int main() {



  return 0;
}