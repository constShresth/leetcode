#include <iostream>
using namespace std;

class Solution {
private:
  int timer = 1;
  void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis, vector<int>& tin, vector<int>& low, vector<vector<int>>& bridges) {
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    for (auto it : adj[node]) {
      if (it == parent) continue;
      if (!vis[it]) {
        dfs(it, node, adj, vis, tin, low, bridges);
        low[node] = min(low[node], low[it]);
        if (low[it] > tin[node]) {
          bridges.push_back({ node,it });
        }
      }
      else {
        low[node] = min(low[node], low[it]);
      }
    }
  }
public:
  vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> adj(n);
    for (auto it : connections) {
      adj[it[0]].push_back(it[1]);
      adj[it[1]].push_back(it[0]);
    }
    vector<int> vis(n, 0);
    vector<int> tin(n);
    vector<int> low(n);
    vector<vector<int>> bridges;
    dfs(0, -1, adj, vis, tin, low, bridges);
    return bridges;
    // o(v+2e), o(v+2e) + o(3n)
  }
};

int main() {



  return 0;
}