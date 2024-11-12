#include <iostream>
using namespace std;

class Solution {
public:
  int f(int i, int j, int n, vector<vector<int>>& items, vector<int>& queries, vector<int>& dp) {
    if (i == n) return 0;
    if (dp[i] != -1) return dp[i];
    int notTake = f(i + 1, j, n, items, queries, dp);
    int take = 0;
    if (items[i][0] <= queries[j]) {
      take = items[i][1];
    }
    return dp[i] = max(take, notTake);
  }
  static bool cmp(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
  }
  vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
    int n = items.size();
    sort(items.begin(), items.end(), cmp);

    vector<int> ans(queries.size());
    vector<int> prices;

    for (int i = 0; i < n; i++) {
      prices.push_back(items[i][0]);
      if (i != 0)
        items[i][1] = max(items[i][1], items[i - 1][1]);
    }

    for (int i = 0; i < queries.size();i++) {

      int index = lower_bound(prices.begin(), prices.end(), queries[i]) - prices.begin();
      if (index == 0 && queries[i] < prices[index]) ans[i] = 0;
      else if (index == n || queries[i] < prices[index]) {
        ans[i] = items[index - 1][1];
      }
      else ans[i] = items[index][1];
    }
    return ans;

    //tle
    // vector<int> ans;
    // for(int j = 0; j<queries.size();j++){
    //     vector<int> dp(n+1,0);
    //     int res;
    //     for(int i = n-1; i>=0; i--){
    //         int notTake = dp[i+1];
    //         int take = 0;
    //         if(items[i][0]<=queries[j]){
    //             take = items[i][1];
    //         }
    //         dp[i] = max(take,notTake);
    //         res = dp[i];
    //     }
    //     ans.push_back(res);
    // }
    // return ans;
    // vector<int> ans;
    // for(int i = 0; i<queries.size(); i++){
    //     vector<int> dp(n,-1);
    //     int res = f(0,i,n,items,queries,dp);
    //     ans.push_back(res);
    // }
    // return ans;
  }
};

int main() {



  return 0;
}