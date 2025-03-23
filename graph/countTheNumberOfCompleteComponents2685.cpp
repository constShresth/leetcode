#include <iostream>
using namespace std;

class Solution {
private:
  void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, vector<int>& component) {
    vis[node] = 1;
    component.push_back(node);

    for (auto it : adj[node]) {
      if (!vis[it]) {
        dfs(it, vis, adj, component);
      }
    }
  }
public:
  int countCompleteComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    for (auto it : edges) {
      adj[it[0]].push_back(it[1]);
      adj[it[1]].push_back(it[0]);
    }
    vector<int> vis(n, 0);
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        vector<int> component;
        dfs(i, vis, adj, component);
        bool flag = true;
        int s = component.size();
        for (auto it : component) {
          if (s - 1 != adj[it].size()) {
            flag = false;
            break;
          }
        }
        if (flag) count++;
      }
    }
    return count;
  }
};

int main() {



  return 0;
}