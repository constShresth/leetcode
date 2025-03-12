#include <iostream>
using namespace std;

class Solution {
public:
  int maximumCount(vector<int>& nums) {
    int cp = 0;
    int cn = 0;
    int n = nums.size();
    int fz = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
    int fp = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
    if (fz == n && fp == n) return n;
    if (fz != n) cn = fz;
    if (fp != n) cp = n - fp;
    return max(cp, cn);

    // for(auto it:nums){
    //     if(it<0) cn++;
    //     else if(it>0) cp++;
    // }
    // return max(cp,cn);
  }
};

int main() {



  return 0;
}