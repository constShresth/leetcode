#include <iostream>
using namespace std;

class Solution {
public:
  int maximumRectangleArea(vector<int>& histo) {
    stack<int> st;
    int n = histo.size();
    int maxi = 0;
    for (int i = 0; i <= n; i++) {
      while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
        int height = histo[st.top()];
        st.pop();
        int width;
        if (st.empty()) width = i;
        else width = i - st.top() - 1;
        int s = min(height, width);
        // converted to square area
        maxi = max(maxi, s * s);
      }
      st.push(i);
    }
    return maxi;
  }

  int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    // int ans = 0;
    // vector<int> height(n,0);
    // int maxi = 0;
    // for(int i = 0; i<m; i++){
    //     for(int j = 0; j<n; j++){
    //         if(matrix[i][j]=='1') height[j]++;
    //         else height[j] = 0;
    //     }
    //     int area = maximumRectangleArea(height);
    //     maxi = max(maxi,area);
    // }
    // return maxi;

    vector<vector<int>> dp(m, vector<int>(n, 0));

    int side = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0) dp[0][j] = matrix[0][j] - '0';
        else if (j == 0) dp[i][0] = matrix[i][0] - '0';
        else if (matrix[i][j] == '1') {
          dp[i][j] = 1 + min({ dp[i - 1][j - 1],
                              dp[i - 1][j],
                              dp[i][j - 1] });
        }
        side = max(side, dp[i][j]);
      }
    }
    return side * side;

  }
};

int main() {



  return 0;
}