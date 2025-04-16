#include <iostream>
using namespace std;

class Solution {
public:
  int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    int n = arr.size();
    int cnt = 0;
    vector<int> prefixCnt(1001, 0);
    for (int j = 0; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (abs(arr[j] - arr[k]) <= b) {
          int l = max(arr[j] - a, arr[k] - c);
          int r = min(arr[j] + a, arr[k] + c);
          l = max(l, 0);
          r = min(r, 1000);
          if (l <= r) {
            cnt += prefixCnt[r] - (l > 0 ? prefixCnt[l - 1] : 0);
          }
        }
      }
      for (int ind = arr[j]; ind < 1001; ind++) {
        prefixCnt[ind]++;
      }
    }
    return cnt;
  }
};

int main() {



  return 0;
}