#include <iostream>
using namespace std;

class Solution {
private:
  bool check(int startNode, vector<vector<int>>& graph, vector<int>& vis) {
    queue<int> q;
    q.push(startNode);
    vis[startNode] = 0;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      for (auto it : graph[node]) {
        if (vis[it] == -1) {
          vis[it] = !vis[node];
          q.push(it);
        }
        else if (vis[it] == vis[node]) {
          return false;
        }
      }
    }
    return true;
  }
public:
  bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> vis(n, -1);
    for (int i = 0; i < n; i++) {
      if (vis[i] == -1) {
        if (check(i, graph, vis) == false) return false;
      }
    }
    return true;
    // o(n) + o(n+2E), o(n)
  }
};

int main() {



  return 0;
}