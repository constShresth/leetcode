#include <iostream>
using namespace std;

class Solution {
public:
  int longestNiceSubarray(vector<int>& nums) {
    int cur = nums[0];
    int n = nums.size();
    int l = 0;
    int r = 1;
    int maxi = 1;
    while (r < n) {
      if ((nums[r] & cur) == 0) {
        cur = cur | nums[r];
        maxi = max(maxi, r - l + 1);
        r++;
      }
      else {
        while (nums[r] & cur) {
          cur = cur ^ nums[l];
          l++;
        }
      }
    }
    return maxi;
  }
};

int main() {



  return 0;
}