#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    unordered_map<int, int> umap;
    int n = grid.size();
    vector<int> res(2, -1);
    for (int i = 0; i < n; i++) {
      for (auto it : grid[i]) {
        umap[it]++;
        if (umap[it] == 2) res[0] = it;
      }
    }
    for (int i = 1; i <= n * n; i++) {
      if (umap.find(i) == umap.end()) {
        res[1] = i;
        break;
      }
    }
    return res;
  }
};

int main() {



  return 0;
}