#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
  int n = intervals.size();
  vector<vector<int>> res;
  int i = 0;
  while (i < n && intervals[i][1] < newInterval[0]) {
    res.push_back(intervals[i]);
    i++;
  }while (i < n && intervals[i][0] <= newInterval[1]) {
    newInterval[1] = max(newInterval[1], intervals[i][1]);
    newInterval[0] = min(newInterval[0], intervals[i][0]);
    i++;
  }res.push_back(newInterval);
  while (i < n) {
    res.push_back(intervals[i]);
    i++;
  }
  return res;

}

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    if (intervals.size() == 0) return { newInterval };
    int start = newInterval[0];
    int end = newInterval[1];
    int startIndex;
    for (int i = 0; i < intervals.size(); i++) {
      if (i == 0 && end < intervals[i][0]) {
        intervals.insert(intervals.begin(), newInterval);
        break;
      }
      if (i == intervals.size() - 1 && start > intervals[i][1]) {
        intervals.push_back(newInterval);
        break;
      }
      if (start <= intervals[i][0]) {
        if (end < intervals[i][0]) {
          intervals.insert(intervals.begin() + i, newInterval);
          return intervals;
        }
        intervals[i][0] = start;
      }
      if (start <= intervals[i][1]) {
        if (end <= intervals[i][1]) {
          return intervals;
        }
        startIndex = i;
        if ((i + 1) < intervals.size() && end > intervals[i][1]) {
          i++;
        }
        else if (end > intervals[i][1]) {
          intervals[i][1] = end;
          break;
        }
        if (end < intervals[i][0]) {
          intervals[startIndex][1] = end;
          break;
        }
        else {
          while (i < intervals.size() && end>intervals[i][1]) {
            intervals.erase(intervals.begin() + i);
          }
          if (i >= intervals.size()) {
            intervals[startIndex][1] = end;
            break;
          }
          else {
            if (end < intervals[i][0]) {
              intervals[startIndex][1] = end;
            }
            else {
              intervals[startIndex][1] = intervals[i][1];
              intervals.erase(intervals.begin() + i);
            }

            break;
          }
        }
      }
    }
    return intervals;
  }
};
int main() {



  return 0;
}