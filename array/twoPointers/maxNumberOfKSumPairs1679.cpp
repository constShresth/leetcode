#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxOperations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int left = 0;
    int right = nums.size() - 1;
    int res = 0;
    while (left < right) {
      int sum = nums[left] + nums[right];
      if (sum == k) {
        res++;
        left++;
        right--;
      }
      else if (sum > k) {
        right--;
      }
      else left++;
    }
    return res;
  }
};

int main() {



  return 0;
}