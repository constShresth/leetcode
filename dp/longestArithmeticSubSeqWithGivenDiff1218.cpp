#include <iostream>
using namespace std;

class Solution {
public:
  int f(int i, int prev, vector<int>& arr, int diff, int n, vector<vector<int>>& dp) {
    if (i == n) return 0;

    if (dp[i][prev + 1] != -1) return dp[i][prev + 1];

    int len = 0 + f(i + 1, prev, arr, diff, n, dp);
    if (prev == -1 || arr[i] - arr[prev] == diff) {
      len = max(len, 1 + f(i + 1, i, arr, diff, n, dp));
    }
    return dp[i][prev + 1] = len;
  }
  int longestSubsequence(vector<int>& arr, int difference) {
    int n = arr.size();
    unordered_map<int, int> dp;
    int ans = 1;
    for (int i = 0; i < n; i++) {
      int prev = arr[i] - difference;
      dp[arr[i]] = 1 + dp[prev];
      //if dp[prev] doesn't exist then it return 0;
      ans = max(ans, dp[arr[i]]);
    }
    return ans;

    //memory limit exceed
    // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    // return f(0,-1,arr,difference,n,dp);

    //tle
    // vector<int> dp(n,1);
    // int maxi = 1;
    // for(int i = 0; i<n; i++){
    //     for(int prev = 0; prev<i; prev++){
    //         int diff = arr[i] - arr[prev];
    //         if(diff==difference && 1+dp[prev] > dp[i]){
    //             dp[i] = 1 + dp[prev];
    //         }
    //     }
    //     maxi = max(maxi,dp[i]);
    // }
    // return maxi;
  }
};

int main() {



  return 0;
}