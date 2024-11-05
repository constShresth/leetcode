#include <iostream>
using namespace std;

class Solution {
public:
  int f(int i, vector<int>& arr, int k, int n, vector<int> dp) {
    if (i == n) return 0;

    if (dp[i] != -1) return dp[i];

    int len = 0, maxi = INT_MIN;
    int maxSum = 0;
    for (int j = i; j < min(n, i + k); j++) {
      len++;
      maxi = max(maxi, arr[j]);
      int sum = len * maxi + f(j + 1, arr, k, n, dp);
      maxSum = max(maxSum, sum);
    }
    return dp[i] = maxSum;
  }
  int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    // vector<int> dp(n,-1);
    // return f(0,arr,k,n,dp);

    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
      int len = 0, maxi = INT_MIN;
      int maxSum = 0;
      for (int j = i; j < min(n, i + k); j++) {
        len++;
        maxi = max(maxi, arr[j]);
        int sum = len * maxi + dp[j + 1];
        maxSum = max(maxSum, sum);
      }
      dp[i] = maxSum;
    }
    return dp[0];
  }
};

int main() {



  return 0;
}