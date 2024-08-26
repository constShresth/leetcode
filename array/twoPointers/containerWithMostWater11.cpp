#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int maxWater = 0;
    while (left < right) {
      int minHeight = min(height[left], height[right]);
      int maxWidth = right - left;
      int currentWater = minHeight * maxWidth;
      maxWater = max(maxWater, currentWater);
      if (height[left] > height[right]) {
        right--;
      }
      else {
        left++;
      }
    }
    return maxWater;
  }
};

int main() {



  return 0;
}