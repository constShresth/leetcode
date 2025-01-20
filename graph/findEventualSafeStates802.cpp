#include <iostream>
using namespace std;

class Solution {
private:
  bool dfs(int i, vector<int>& vis, vector<vector<int>>& adj, vector<int>& pathVis, vector<int>& check) {
    vis[i] = 1;
    pathVis[i] = 1;
    for (auto it : adj[i]) {
      if (!vis[it]) {
        if (dfs(it, vis, adj, pathVis, check)) return true;;
      }
      else if (pathVis[it]) {
        return true;
      }
    }
    check[i] = 1;
    pathVis[i] = 0;
    return false;
  }
public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> vis(n, 0);
    vector<int> pathVis(n, 0);
    vector<int> check(n, 0);
    vector<int> safeNodes;
    for (int i = 0; i < n;i++) {
      if (!vis[i]) {
        dfs(i, vis, graph, pathVis, check);
      }
    }
    for (int i = 0; i < n;i++) {
      if (check[i]) {
        safeNodes.push_back(i);
      }
    }
    return safeNodes;
    // o(n+e) + o(n), o(n)
  }
};

int main() {



  return 0;
}