#include <iostream>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < n; i++) {
      if (i == 0 || intervals[i][0] > res.back()[1]) res.push_back(intervals[i]);
      else res.back()[1] = max(res.back()[1], intervals[i][1]);
    }
    // int i = 0;
    // int j = 0;
    // while (i < intervals.size()) {
    //   int end = intervals[j][1];
    //   while ((i + 1) < (intervals.size()) && end >= intervals[i + 1][0]) {
    //     i++;
    //     end = max(end, intervals[i][1]);
    //   };
    //   res.push_back({ intervals[j][0],end });
    //   i++;
    //   j = i;
    // }
    return res;
  }
};

int main() {



  return 0;
}