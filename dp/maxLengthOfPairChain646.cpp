#include <iostream>
using namespace std;

class Solution {
public:
  static bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
  }
  int f(int i, int prev, vector<vector<int>>& pairs, int n, vector<vector<int>>& dp) {
    if (i == n) return 0;

    if (dp[i][prev + 1] != -1) return dp[i][prev + 1];

    int notTake = 0 + f(i + 1, prev, pairs, n, dp);
    int take = INT_MIN;
    if (prev == -1 || pairs[i][0] > pairs[prev][1]) {
      take = 1 + f(i + 1, i, pairs, n, dp);
    }
    return dp[i][prev + 1] = max(take, notTake);
  }
  int findLongestChain(vector<vector<int>>& pairs) {
    int n = pairs.size();
    // sort(pairs.begin(),pairs.end(),cmp);
    // vector<vector<int>> dp(n,vector<int> (n+1,-1));
    // return f(0,-1,pairs,n,dp);
    // vector<int> dp(n,1);
    // int maxi = 1;
    // for(int i = 0; i<n; i++){
    //     for(int prev = 0; prev<i; prev++){
    //         if(pairs[i][0]>pairs[prev][1] && 1+dp[prev]>dp[i]){
    //             dp[i] = 1 + dp[prev];
    //         }
    //     }
    //     maxi = max(maxi,dp[i]);
    // }
    // return maxi;

    //greedy
    sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
      return a[1] < b[1];
      });
    int count = 1;
    int prev = pairs[0][1];
    for (int i = 1; i < pairs.size(); i++) {
      if (pairs[i][0] > prev) {
        count++;
        prev = pairs[i][1];
      }
    }
    return count;
  }
};

int main() {



  return 0;
}