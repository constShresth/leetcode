#include <iostream>
using namespace std;

class Solution {
private:
  int mod = 7 + 1e9;
  int dfs(int node, int n, vector<vector<pair<int, int>>>& adj, vector<int>& dist, vector<int>& dp) {
    if (node == n) return 1;

    if (dp[node] != -1) return dp[node];

    int sum = 0;
    for (auto it : adj[node]) {
      if (dist[it.first] < dist[node]) {
        sum = (sum + dfs(it.first, n, adj, dist, dp)) % mod;
      }
    }
    return dp[node] = sum;
  }
public:
  int countRestrictedPaths(int n, vector<vector<int>>& edges) {
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto it : edges) {
      int u = it[0];
      int v = it[1];
      int wt = it[2];
      adj[u].push_back({ v,wt });
      adj[v].push_back({ u,wt });
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,n });
    vector<int> dist(n + 1, INT_MAX);
    dist[n] = 0;
    while (!pq.empty()) {
      int wt = pq.top().first;
      int node = pq.top().second;
      pq.pop();
      for (auto it : adj[node]) {
        int v = it.first;
        int d = it.second;
        if (dist[v] > wt + d) {
          dist[v] = wt + d;
          pq.push({ dist[v],v });
        }
      }
    }

    vector<int> dp(n + 1, -1);

    int res = dfs(1, n, adj, dist, dp);
    return res;
  }
};

int main() {



  return 0;
}