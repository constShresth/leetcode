#include <iostream>
using namespace std;

class Solution {
public:
  int maxScore(vector<int>& cardPoints, int k) {
    int ans = 0;
    int n = cardPoints.size();
    int lSum = 0, rSum = 0;
    for (int i = 0; i < k; i++) lSum += cardPoints[i];
    ans = lSum;
    int r = n - 1;
    for (int l = k - 1; l >= 0; l--) {
      lSum -= cardPoints[l];
      rSum += cardPoints[r];
      r--;
      ans = max(ans, lSum + rSum);
    }
    return ans;
  }
};

int main() {



  return 0;
}