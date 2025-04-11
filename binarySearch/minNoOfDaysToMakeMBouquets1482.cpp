#include <iostream>
using namespace std;

class Solution {
private:
  int isPossible(vector<int>& bloomDay, int m, int k, int mid) {
    int bouquets = 0;
    int cnt = 0;
    int n = bloomDay.size();
    for (int j = 0; j < n; j++) {
      if (bloomDay[j] <= mid) {
        cnt++;
      }      
else {
        bouquets += (cnt / k);
        cnt = 0;
      }
    }
    bouquets += (cnt / k);
    return bouquets;
  }
public:
  int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    long long flowers = (long long)m * k;
    if (flowers > n) return -1;
    int high = INT_MIN;
    int low = INT_MAX;
    for (int i = 0; i < n; i++) {
      high = max(high, bloomDay[i]);
      low = min(low, bloomDay[i]);
    }
    int ans = -1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int bouquets = isPossible(bloomDay, m, k, mid);
      if (bouquets >= m) {
        ans = mid;
        high = mid - 1;
      }
      else low = mid + 1;
    }
    return ans;
  }
};

int main() {



  return 0;
}