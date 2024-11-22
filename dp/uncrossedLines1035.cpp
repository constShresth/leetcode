#include <iostream>
using namespace std;

class Solution {
public:
  int longestCommonSubsequence(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for (int j = 0; j <= m; j++) prev[j] = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (nums1[i - 1] == nums2[j - 1]) curr[j] = 1 + prev[j - 1];
        else curr[j] = max(prev[j], curr[j - 1]);
      }
      prev = curr;
    }

    return prev[m];
  }
  int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    return longestCommonSubsequence(nums1, nums2);
  }
};

int main() {



  return 0;
}