#include <iostream>
using namespace std;

class Solution {
private:
  bool dfsBob(int node, int parent, int time, vector<vector<int>>& adj, unordered_map<int, int>& umap) {
    if (node == 0) {
      umap[node] = time;
      return true;
    }
    for (auto it : adj[node]) {
      if (it == parent) continue;
      if (dfsBob(it, node, time + 1, adj, umap)) {
        umap[node] = time;
        return true;
      }
    }
    return false;
  }
  void dfs(int node, int parent, int time, int profit, int& maxi, vector<vector<int>>& adj, unordered_map<int, int>& umap, vector<int>& amount) {
    if (umap.find(node) == umap.end() || time < umap[node]) {
      profit += amount[node];
    }
    else if (time == umap[node]) {
      profit += amount[node] / 2;
    }
    bool isLeaf = true;
    for (auto it : adj[node]) {
      if (it == parent) {
        continue;
      };
      isLeaf = false;
      dfs(it, node, time + 1, profit, maxi, adj, umap, amount);
    }
    if (isLeaf) {
      maxi = max(maxi, profit);
    }
  }
public:
  int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
    int n = amount.size();
    vector<vector<int>> adj(n);
    for (auto it : edges) {
      adj[it[0]].push_back(it[1]);
      adj[it[1]].push_back(it[0]);
    }
    unordered_map<int, int> umap;
    dfsBob(bob, -1, 0, adj, umap);

    int maxi = INT_MIN;
    dfs(0, -1, 0, 0, maxi, adj, umap, amount);
    return maxi;
  }
};

int main() {



  return 0;
}