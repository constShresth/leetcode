#include <iostream>
using namespace std;

class Solution {
public:
  void bfs(int node, vector<vector<int>>& adjM, vector<bool>& vis) {
    queue<int> q;
    q.push(node);
    vis[node] = true;
    while (!q.empty()) {
      int cur = q.front(); q.pop();
      for (int i = 0; i < adjM[cur].size(); i++) {
        bool connected = adjM[cur][i];
        if (connected && !vis[i]) {
          vis[i] = true;
          q.push(i);
        }
      }
    }
  }
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<bool> vis(n, false);
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        count++;
        bfs(i, isConnected, vis);
      }
    }
    return count;
    // o(n) + o(n*n), o(n)
  }
};

int main() {



  return 0;
}