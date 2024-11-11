#include <iostream>
using namespace std;

class Solution {
public:
  int f(int i, int prev, vector<int>& ob, int n, vector<vector<int>>& dp) {
    if (i == -1) return 0;
    if (dp[i][prev] != -1) return dp[i][prev];
    int notTake = 0 + f(i - 1, prev, ob, n, dp);
    int take = INT_MIN;
    if (ob[i] <= ob[prev]) {
      take = 1 + f(i - 1, i, ob, n, dp);
    }
    return dp[i][prev] = max(take, notTake);
  }
  vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
    int n = obstacles.size();
    vector<int> temp;
    vector<int> res;
    temp.push_back(obstacles[0]);
    res.push_back(1);
    for (int i = 1; i < n; i++) {
      if (obstacles[i] >= temp.back()) {
        temp.push_back(obstacles[i]);
        res.push_back(temp.size());
      }
      else {
        int index = upper_bound(temp.begin(), temp.end(), obstacles[i]) - temp.begin();
        temp[index] = obstacles[i];
        res.push_back(index + 1);
      }
    }
    return res;
    // int j = n-2;
    // while(j>=0){
    //     if(obstacles[j]<=9){
    //         temp.push_back(obstacles[j]);
    //         break;
    //     }
    // }
    // temp.push_back(obstacles[n-1]);
    // for(int j = n-2; j>=0; j--){
    //     if(obstacles[j]<=temp.back()){
    //         temp.push_back(obstacles[j]);
    //     }else{
    //         int index = upper_bound(temp.begin(),temp.end(),obstacles[j]) - temp.begin();
    //         temp[index] = obstacles[j];
    //     }
    // }
    // vector<int> res;
    // for(int i=n-2; i>=0; i--){
    //     vector<vector<int>> dp(n,vector<int> (n,-1));
    //     int ans = f(i,i+1,obstacles,i,dp);
    //     res.push_back(ans+1);
    // }
    // res.push_back(1);
    // reverse(res.begin(),res.end());
    // return res;
  }
};

int main() {



  return 0;
}