#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<int> indegree(n, 0); // o(n)
    vector<vector<int>> adj(n); // o(n+e)
    for (auto it : edges) {
      adj[it[0]].push_back(it[1]);
      indegree[it[1]]++;
    }
    // o(e)
    queue<int> q; // o(n)
    for (int i = 0; i < n; i++) {
      if (indegree[i] == 0) q.push(i);
    }
    // o(n)
    vector<vector<int>> res(n); // o(n*m)
    while (!q.empty()) {
      // o(n)
      int node = q.front(); q.pop();
      for (auto it : adj[node]) {
        // o(e) in total
        indegree[it]--;
        for (auto it2 : res[node]) {
          res[it].push_back(it2);
        }
        res[it].push_back(node);
        if (indegree[it] == 0) {
          set<int> ancestor(res[it].begin(), res[it].end()); // o(mlog(m)), m->size of res[it];
          res[it] = vector<int>(ancestor.begin(), ancestor.end()); // o(m)
          q.push(it);
        };
      }

    }
    return res;
    // o(e+n+n+e*(mlog(m))) => o(2n + e + e(mlog(m)))
    // o(n + e*mlog(m)), o(n+n+e+n+n*m+m)=> o(3n+e+n*m+m); m equal to n in worse case;
  }
};

int main() {



  return 0;
}