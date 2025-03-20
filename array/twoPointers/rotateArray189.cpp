#include <iostream>
using namespace std;

class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    // for(int i=0; i<k; i++){
    //     for(int j=1;j<nums.size();j++){
    //         swap(nums[0],nums[j]);
    //     }
    // }
    //tle

    vector<int> arr(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      int j = (i + k) % nums.size();
      arr[j] = nums[i];
    }
    nums = arr;

    // reverse(nums.begin(),nums.end());
    // reverse(nums.begin(),nums.begin()+k);
    // reverse(nums.begin()+k,nums.end());
    // this code won't work because k can be greater than size of array acc. to contraints

  }
};

int main() {



  return 0;
}