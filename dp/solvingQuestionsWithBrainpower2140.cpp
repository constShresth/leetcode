#include <iostream>
using namespace std;

class Solution {
public:
  long long f(int index, int n, vector<vector<int>>& questions, vector<long long>& dp) {
    if (index == n - 1) return questions[index][0];
    if (index > n - 1) return 0;

    if (dp[index] != -1) return dp[index];

    long long pick = questions[index][0] + f(index + 1 + questions[index][1], n, questions, dp);
    long long notPick = f(index + 1, n, questions, dp);

    return dp[index] = max(pick, notPick);
  }

  long long mostPoints(vector<vector<int>>& questions) {
    int n = questions.size();
    vector<long long> dp(n, -1);
    // return f(0,n,questions,dp);
    dp[n - 1] = questions[n - 1][0];
    for (int index = n - 2; index >= 0; index--) {
      long long pick = questions[index][0];
      if (index + 1 + questions[index][1] <= n - 1) pick += dp[index + 1 + questions[index][1]];
      long long notPick = dp[index + 1];

      dp[index] = max(pick, notPick);
    }
    return dp[0];
  }
};

int main() {



  return 0;
}