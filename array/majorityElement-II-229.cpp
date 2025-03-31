#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> res;
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;
    for (int i = 0; i < n; i++) {
      if (cnt1 == 0 && nums[i] != el2) {
        cnt1 = 1;
        el1 = nums[i];
      }
      else if (cnt2 == 0 && nums[i] != el1) {
        cnt2 = 1;
        el2 = nums[i];
      }
      else if (nums[i] == el1) cnt1++;
      else if (nums[i] == el2) cnt2++;
      else { cnt1--, cnt2--; };
    }
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] == el1) cnt1++;
      else if (nums[i] == el2) cnt2++;
    }
    if (cnt1 > n / 3) res.push_back(el1);
    if (cnt2 > n / 3) res.push_back(el2);
    return res;
    // o(2n), o(1)
  }
};

int main() {



  return 0;
}