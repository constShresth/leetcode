#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    int m = grid.size();
    int n = grid[0].size();

    vector<pair<int, int>> v;
    for (int i = 0; i < queries.size(); i++) v.push_back({ queries[i],i });
    sort(v.begin(), v.end());

    vector<int> res(queries.size(), 0);
    vector<vector<int>> vis(m, vector<int>(n, 0));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    pq.push({ grid[0][0],{0,0} });
    vis[0][0] = 1;
    int ans = 0;

    for (auto it : v) {
      int node = it.first;
      int ind = it.second;

      while (!pq.empty() && node > pq.top().first) {
        auto [val, coords] = pq.top(); pq.pop();
        auto [row, col] = coords;
        ans++;
        vector<int> dr = { -1,0,+1,0 };
        vector<int> dc = { 0,+1,0,-1 };

        for (int i = 0; i < 4; i++) {
          int nr = row + dr[i];
          int nc = col + dc[i];

          if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc]) {
            pq.push({ grid[nr][nc],{nr,nc} });
            vis[nr][nc] = 1;
          }
        }
      }
      res[ind] = ans;
    }
    return res;
  }
};

int main() {



  return 0;
}