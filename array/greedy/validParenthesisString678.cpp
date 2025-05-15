#include <iostream>
using namespace std;

class Solution {
private:
  vector<vector<int>> dp;
  bool f(int ind, int cnt, string& s) {
    if (cnt < 0) return false;
    if (ind == s.size()) return cnt == 0;

    if (dp[ind][cnt] != -1) return dp[ind][cnt];

    bool res = false;
    if (s[ind] == '(') {
      res = f(ind + 1, cnt + 1, s);
    }    
else if (s[ind] == ')') {
      res = f(ind + 1, cnt - 1, s);
    }
    else {
      res = f(ind + 1, cnt + 1, s) || f(ind + 1, cnt - 1, s) || f(ind + 1, cnt, s);
    }
    return dp[ind][cnt] = res;
  }
public:
  bool checkValidString(string s) {
    int n = s.size();
    // dp.resize(n,vector<int>(n,-1));
    // return f(0,0,s);
    int maxi = 0, mini = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        mini++;
        maxi++;
      }
      else if (s[i] == ')') {
        mini--;
        maxi--;
      }
      else {
        mini--;
        maxi++;
      }
      if (mini < 0) mini = 0;
      if (maxi < 0) return false;
    }
    return mini == 0;
  }
};

int main() {



  return 0;
}