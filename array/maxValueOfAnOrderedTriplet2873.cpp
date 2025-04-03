#include <iostream>
using namespace std;

class Solution {
public:
  long long maximumTripletValue(vector<int>& nums) {
    int n = nums.size();
    int left = nums[0];
    vector<int> maxi(n);
    maxi[n - 1] = nums[n - 1];
    long long res = 0;
    for (int i = n - 2; i >= 0; i--) {
      maxi[i] = max(nums[i], maxi[i + 1]);
    }
    for (int j = 1; j < n - 1; j++) {
      if (nums[j] > left) {
        left = nums[j];
        continue;
      }
      res = max(res, (left - nums[j]) * (long long)maxi[j + 1]);
    }
    return res;
  }
};

int main() {



  return 0;
}