#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);
    int pi = 0;
    int ni = 1;
    for (int i = 0; i < n; i++) {
      if (nums[i] > 0) {
        res[pi] = nums[i];
        pi += 2;
      }
      else {
        res[ni] = nums[i];
        ni += 2;
      }
    }
    return res;


    // vector<int> pos;
    // vector<int> neg;
    // int n = nums.size();
    // for (int i = 0; i < n; i++) {
    //   if (nums[i] > 0) pos.push_back(nums[i]);
    //   else neg.push_back(nums[i]);
    // }
    // for (int i = 0; i < n / 2; i++) {
    //   nums[2 * i] = pos[i];
    //   nums[2 * i + 1] = neg[i];
    // }
    // return nums;
  }
};

int main() {



  return 0;
}