#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxOnes = 0;
    int count = 0;
    int left = 0;
    int right = 0;
    for (auto num : nums) {
      if (num == 1) {
        count++;
        maxOnes = max(maxOnes, count);
      }
      else count = 0;
    }
    return maxOnes;
  }
};

int main() {



  return 0;
}