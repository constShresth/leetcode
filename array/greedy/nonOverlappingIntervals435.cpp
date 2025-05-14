#include <iostream>
using namespace std;

class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    // same as n meetings in one room
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
      return a[1] < b[1];
      });
    int lastEnd = intervals[0][1], cnt = 1;
    for (int i = 1; i < n; i++) {
      int startTime = intervals[i][0];
      int endTime = intervals[i][1];
      if (startTime >= lastEnd) {
        cnt++;
        lastEnd = endTime;
      }
    }
    return n - cnt;
  }
};

int main() {



  return 0;
}