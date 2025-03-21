#include <iostream>
using namespace std;

class DisJointSet {
  vector<int> parent, rank, size;
public:
  DisJointSet(int n) {
    parent.resize(n);
    rank.resize(n, 0);
    size.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }
  int findUParent(int node) {
    if (parent[node] == node) {
      return node;
    }
    return parent[node] = findUParent(parent[node]);
  }

  void unionByRank(int u, int v) {
    int pu = findUParent(u);
    int pv = findUParent(v);
    if (pu != pv) {
      if (rank[pu] < rank[pv]) {
        parent[pu] = pv;
      }
      else if (rank[pu] > rank[pv]) {
        parent[pv] = pu;
      }
      else {
        parent[pu] = pv;
        rank[pv]++;
      }
    }
  }

  void unionBySize(int u, int v) {
    int pu = findUParent(u);
    int pv = findUParent(v);
    if (pu != pv) {
      if (size[pu] < size[pv]) {
        parent[pu] = pv;
        size[pv] += size[pu];
      }
      else {
        parent[pv] = pu;
        size[pu] += size[pv];
      }
    }
  }
};

class Solution {
public:
  vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
    DisJointSet dsu(n);
    for (auto it : edges) {
      dsu.unionBySize(it[0], it[1]);
    }

    unordered_map<int, int> componentCost;
    for (auto it : edges) {
      int root = dsu.findUParent(it[0]);
      if (componentCost.find(root) == componentCost.end()) {
        componentCost[root] = it[2];
      }
      else {
        componentCost[root] &= it[2];
      }
    }

    vector<int> res;
    for (auto it : query) {
      if (dsu.findUParent(it[0]) == dsu.findUParent(it[1])) {
        int root = dsu.findUParent(it[0]);
        res.push_back(componentCost[root]);
      }
      else {
        res.push_back(-1);
      }
    }
    return res;

  }
};

int main() {



  return 0;
}