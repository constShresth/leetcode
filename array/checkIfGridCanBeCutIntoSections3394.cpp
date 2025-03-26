#include <iostream>
using namespace std;

class Solution {
public:
  bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
    vector<pair<int, int>> x;
    vector<pair<int, int>> y;
    for (auto it : rectangles) {
      x.push_back({ it[0],it[2] });
      y.push_back({ it[1],it[3] });
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int cntX = 0;
    int cntY = 0;
    int endX = x[0].second;
    int endY = y[0].second;
    for (int i = 0; i < x.size() - 1; i++) {
      if (x[i + 1].first >= endX) {
        cntX++;
      }
      if (y[i + 1].first >= endY) {
        cntY++;
      }
      endX = max(endX, x[i + 1].second);
      endY = max(endY, y[i + 1].second);
    }
    return cntX >= 2 || cntY >= 2;
  }
};

int main() {



  return 0;
}