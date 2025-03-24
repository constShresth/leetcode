#include <iostream>
using namespace std;

class Solution {
public:
  int countDays(int days, vector<vector<int>>& meetings) {
    sort(meetings.begin(), meetings.end());
    int n = days;
    int prev = 0;
    for (auto it : meetings) {
      int start = it[0];
      int end = it[1];
      start = max(start, prev + 1);
      int len = end - start + 1;
      days -= max(len, 0); // in case len is negative
      prev = max(prev, end);
    }
    return days;

    // int start = 1;
    // int end = 0;
    // for (int i = 0; i < meetings.size(); i++) {
    //   if (i == 0 || meetings[i][0] > end) {
    //     n = n - (end - start + 1);
    //     start = meetings[i][0];
    //     end = meetings[i][1];
    //   }
    //   else if (meetings[i][0] <= end) {
    //     end = max(meetings[i][1], end);
    //   }
    // }
    // n = n - (end - start + 1);
    // return n;
  }
};

int main() {



  return 0;
}