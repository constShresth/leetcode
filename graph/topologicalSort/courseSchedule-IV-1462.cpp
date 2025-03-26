#include <iostream>
using namespace std;

class Solution {
public:
  vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    int n = numCourses;
    vector<vector<int>> adj(n);
    vector<int> indegree(n);
    for (auto it : prerequisites) {
      adj[it[0]].push_back(it[1]);
      indegree[it[1]]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) if (indegree[i] == 0) q.push(i);

    vector<vector<bool>> isReachable(n, vector<bool>(n, false));
    while (!q.empty()) {
      int node = q.front(); q.pop();
      for (auto it : adj[node]) {
        indegree[it]--;
        isReachable[node][it] = true;
        for (int i = 0; i < n; i++) {
          if (isReachable[i][node]) isReachable[i][it] = true;
        }
        if (indegree[it] == 0) q.push(it);
      }
    }
    vector<bool> res;

    for (auto it : queries) {
      res.push_back(isReachable[it[0]][it[1]]);
    }

    return res;
  }
};

int main() {



  return 0;
}