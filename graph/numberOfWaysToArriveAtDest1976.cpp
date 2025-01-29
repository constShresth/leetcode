#include <iostream>
using namespace std;

class Solution {
public:
  int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> adj(n);
    for (auto it : roads) {
      int u = it[0];
      int v = it[1];
      int time = it[2];
      adj[u].push_back({ v,time });
      adj[v].push_back({ u,time });
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({ 0,0 });
    vector<long long> time(n, LONG_MAX);
    vector<int> path(n, 0);
    time[0] = 0;
    path[0] = 1;
    int mod = 1e9 + 7;
    while (!pq.empty()) {
      long long t1 = pq.top().first;
      int node = pq.top().second;
      pq.pop();

      for (auto it : adj[node]) {
        int v = it.first;
        long long t2 = it.second;
        if (t1 + t2 < time[v]) {
          time[v] = t1 + t2;
          path[v] = path[node];
          pq.push({ t1 + t2,v });
        }
        else if (t1 + t2 == time[v]) {
          path[v] = (path[v] + path[node]) % mod;
        }
      }
    }
    return path[n - 1];

  }
};

int main() {



  return 0;
}