#include <iostream>
using namespace std;

class Solution {
public:
  bool check(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    for (int i = 1; i < n; i++) {
      if (nums[i - 1] > nums[i]) {
        count++;
        if (count > 1) return false;
      }
    }
    if (count == 1 && nums[n - 1] > nums[0]) return false;
    return true;
    // o(n)

    // int n = nums.size();
    // for (int i = 0; i < n; i++) {
    //   bool flag = true;
    //   for (int j = i + 1; j < n + i; j++) {
    //     int cur = nums[j % n];
    //     int prev = nums[(j - 1) % n];
    //     if (prev > cur) flag = false;
    //   }
    //   if (flag) return true;
    // }
    // return false;
    // o(2n)
  }
};

int main() {



  return 0;
}