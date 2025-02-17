#include <iostream>
using namespace std;

class Solution {
private:
  double calculateDistance(int x1, int y1, int x2, int y2) {
    long long xd = (long long)x2 - x1;
    long long yd = (long long)y2 - y1;
    return sqrt(xd * xd + yd * yd);
  }
  void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, int& maxi, int& count) {
    vis[node] = 1;
    for (auto it : adj[node]) {
      if (!vis[it]) {
        count++;
        dfs(it, vis, adj, maxi, count);
      }
    }
  }
public:
  int maximumDetonation(vector<vector<int>>& bombs) {
    int n = bombs.size();
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
      int x1 = bombs[i][0];
      int y1 = bombs[i][1];
      int r1 = bombs[i][2];
      for (int j = i + 1; j < n; j++) {
        int x2 = bombs[j][0];
        int y2 = bombs[j][1];
        int r2 = bombs[j][2];
        double dist = calculateDistance(x1, y1, x2, y2);
        if (r1 >= dist) adj[i].push_back(j);
        if (r2 >= dist) adj[j].push_back(i);
      }
    }
    int maxi = 0;
    for (int i = 0; i < n; i++) {
      vector<int> vis(n, 0);
      int count = 1;
      dfs(i, vis, adj, maxi, count);
      maxi = max(maxi, count);
    }
    return maxi;
  }
};

int main() {



  return 0;
}