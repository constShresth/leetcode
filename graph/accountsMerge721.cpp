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
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, int> umap;
    int n = accounts.size();
    DisJointSet ds(n);
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < accounts[i].size(); j++) {
        if (umap.find(accounts[i][j]) == umap.end()) {
          umap[accounts[i][j]] = i;
        }
        else {
          ds.unionBySize(umap[accounts[i][j]], i);
        }
      }
    }
    vector<vector<string>> v(n);
    for (auto it : umap) {
      string id = it.first;
      int node = ds.findUParent(it.second);
      v[node].push_back(id);
    }
    vector<vector<string>> res;
    for (int i = 0; i < n; i++) {
      if (v[i].size() == 0) continue;
      sort(v[i].begin(), v[i].end());
      vector<string> temp;
      temp.push_back(accounts[i][0]);
      for (auto it : v[i]) {
        temp.push_back(it);
      }
      res.push_back(temp);
    }
    return res;
  }
};

int main() {



  return 0;
}