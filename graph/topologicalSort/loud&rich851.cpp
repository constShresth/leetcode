#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    int n = quiet.size();
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    for (auto it : richer) {
      adj[it[0]].push_back(it[1]);
      indegree[it[1]]++;
    }
    queue<int> q;
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      res[i] = i;
      if (indegree[i] == 0) q.push(i);
    }
    while (!q.empty()) {
      int node = q.front(); q.pop();
      for (auto it : adj[node]) {
        indegree[it]--;
        if (quiet[res[node]] < quiet[res[it]]) {
          res[it] = res[node];
        }
        if (indegree[it] == 0) q.push(it);
      }
    }
    return res;
  }
};

int main() {



  return 0;
}