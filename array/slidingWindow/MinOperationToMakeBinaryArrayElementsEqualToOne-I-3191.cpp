#include <iostream>
using namespace std;

class Solution {
public:
  int minOperations(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] == 0) {
        int j = i;
        while (j < i + 3) {
          if (j == n) return -1;
          if (nums[j] == 0) nums[j] = 1;
          else nums[j] = 0;
          j++;
        }
        count++;
      }
    }
    return count;
  }
};

int main() {



  return 0;
}