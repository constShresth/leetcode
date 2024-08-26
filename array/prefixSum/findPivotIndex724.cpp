#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    vector<int> leftSum(n);
    vector<int> rightSum(n);
    leftSum[0] = 0;
    rightSum[n - 1] = 0;
    for (int i = 1; i < n; i++) {
      leftSum[i] = leftSum[i - 1] + nums[i - 1];
    }
    for (int i = n - 2; i >= 0; i--) {
      rightSum[i] = rightSum[i + 1] + nums[i + 1];
    }
    for (int i = 0; i < n; i++) {
      cout << leftSum[i] << ":" << rightSum[i] << endl;
      if (leftSum[i] == rightSum[i]) return i;
    }
    return -1;
  }
};

int main() {



  return 0;
}