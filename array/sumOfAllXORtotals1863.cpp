#include <iostream>
using namespace std;

class Solution {
private:
  int f(int i, int xr, int sum, int n, vector<int>& nums) {
    if (i >= n) return xr;

    int take = f(i + 1, xr ^ nums[i], sum, n, nums);
    int notTake = f(i + 1, xr, sum, n, nums);

    return take + notTake;
  }
public:
  int subsetXORSum(vector<int>& nums) {
    int n = nums.size();
    return f(0, 0, 0, n, nums);
  }
};

int main() {



  return 0;
}