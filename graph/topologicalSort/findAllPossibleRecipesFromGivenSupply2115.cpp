#include <iostream>
using namespace std;

class Solution {
private:
  void dfs(string node, unordered_map<string, int>& vis, unordered_map<string, vector<string>>& adj, stack<string>& st) {
    vis[node] = 1;
    for (auto it : adj[node]) {
      if (vis.find(it) == vis.end()) {
        dfs(it, vis, adj, st);
      }
    }
    st.push(node);
  }

  vector<string> topologicalSort(vector<string>& recipes, vector<vector<string>>& ingredients) {
    unordered_map<string, vector<string>> adj;
    int n = recipes.size();
    for (int i = 0; i < n; i++) {
      for (auto it : ingredients[i]) {
        adj[it].push_back(recipes[i]);
      }
    }
    stack<string> st;
    unordered_map<string, int> vis;
    for (auto it : recipes) {
      if (vis.find(it) == vis.end()) {
        dfs(it, vis, adj, st);
      }
    }

    vector<string> topoSort;
    while (!st.empty()) {
      topoSort.push_back(st.top());
      st.pop();
    }
    return topoSort;
  }

  bool canCreate(string r, unordered_map<string, int>& rIndex, unordered_map<string, int>& sup, vector<vector<string>>& ingredients) {
    for (auto it : ingredients[rIndex[r]]) {
      if (sup.find(it) == sup.end()) {
        return false;
      }
    }
    return true;
  }
public:
  vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    int n = recipes.size();
    vector<string> topoSort = topologicalSort(recipes, ingredients);

    unordered_map<string, int> rIndex;
    unordered_map<string, int> sup;
    vector<string> res;
    // mapping recipes to its index
    for (int i = 0; i < n; i++) rIndex[recipes[i]] = i;
    for (auto it : supplies) sup[it] = 1;

    for (auto it : topoSort) {
      if (canCreate(it, rIndex, sup, ingredients)) {
        res.push_back(it);
        sup[it] = 1;
      }
    }
    return res;
  }
};

int main() {



  return 0;
}