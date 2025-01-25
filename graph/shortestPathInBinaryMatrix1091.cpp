#include <iostream>
using namespace std;

class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({ 1,{0,0} });
    int n = grid.size();
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    dist[0][0] = 1;
    if (grid[0][0] == 1) return -1;
    while (!pq.empty()) {
      int wt = pq.top().first;
      int row = pq.top().second.first;
      int col = pq.top().second.second;
      pq.pop();

      for (int dr = -1;dr <= 1;dr++) {
        for (int dc = -1;dc <= 1;dc++) {
          if ((dr == 0 && dc != 0) || (dr != 0 && dc == 0) || (dr != 0 && dc != 0)) {
            int nrow = row + dr;
            int ncol = col + dc;
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol<n && grid[nrow][ncol] == 0 && dist[nrow][ncol]>wt + 1) {
              dist[nrow][ncol] = wt + 1;
              pq.push({ wt + 1,{nrow,ncol} });
            }
          }
        }
      }
    }
    return dist[n - 1][n - 1] == 1e9 ? -1 : dist[n - 1][n - 1];
    // o(e *log(v))
  }
};

int main() {



  return 0;
}