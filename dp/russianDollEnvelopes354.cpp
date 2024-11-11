#include <iostream>
using namespace std;

class Solution {
public:
  static bool cmp(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
  }
  int f(int i, int prev, vector<vector<int>>& en, int n, vector<vector<int>>& dp) {
    if (i == n) return 0;

    if (dp[i][prev + 1] != -1) return dp[i][prev + 1];

    int notTake = 0 + f(i + 1, prev, en, n, dp);
    int take = INT_MIN;
    if (prev == -1 || (en[i][0] > en[prev][0] && en[i][1] > en[prev][1])) {
      take = 1 + f(i + 1, i, en, n, dp);
    }
    return dp[i][prev + 1] = max(take, notTake);
  }
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    int n = envelopes.size();
    sort(envelopes.begin(), envelopes.end(), cmp);
    vector<int> temp;
    temp.push_back(envelopes[0][1]);
    for (int i = 1; i < n; i++) {
      if (envelopes[i][1] > temp.back()) {
        temp.push_back(envelopes[i][1]);
      }
      else {
        int index = lower_bound(temp.begin(), temp.end(), envelopes[i][1]) - temp.begin();
        temp[index] = envelopes[i][1];
      }
    }
    return temp.size();

    // vector<vector<int>> dp(n,vector<int>(n+1,-1));
    // return f(0,-1,envelopes,n,dp);

    //tle
    // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    // for(int i = n-1; i>=0; i--){
    //     for(int prev = i-1; prev>=-1; prev--){
    //         int notTake = 0 + dp[i+1][prev+1];
    //         int take = INT_MIN; 
    //         if(prev==-1 || (envelopes[i][0]>envelopes[prev][0] && envelopes[i][1]>envelopes[prev][1])){
    //             take = 1 + dp[i+1][i+1];
    //         }
    //         dp[i][prev+1] = max(take,notTake);
    //     }
    // }
    // return dp[0][-1+1];

    //tle
    // vector<int> next(n+1,0), curr(n+1,0);
    // for(int i = n-1; i>=0; i--){
    //     for(int prev = i-1; prev>=-1; prev--){
    //         int notTake = 0 + next[prev+1];
    //         int take = INT_MIN; 
    //         if(prev==-1 || (envelopes[i][0]>envelopes[prev][0] && envelopes[i][1]>envelopes[prev][1])){
    //             take = 1 + next[i+1];
    //         }
    //         curr[prev+1] = max(take,notTake);
    //     }
    //     next = curr;
    // }
    // return next[-1+1];
  }
};

int main() {



  return 0;
}