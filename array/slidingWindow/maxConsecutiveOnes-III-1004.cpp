#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    int l = 0, r = 0, ans = 0;
    int cnt = 0;
    while (r < n) {
      if (nums[r] == 0) cnt++;
      if (cnt > k) { // used if instead of while because there's no point of 
        // decreasing the length futher
        // for eg: if ans = 9, then what's the point of making the length less than 9
        // because it will always be less than 9 so answer won't change
        // and by this method we can always keep increasing l at every step if cnt>k
        // and keep the length 9 or greater.
        if (nums[l] == 0) cnt--;
        l++;
      }
      ans = max(ans, r - l + 1);
      r++;
    }
    return ans;
  }
};

int main() {



  return 0;
}