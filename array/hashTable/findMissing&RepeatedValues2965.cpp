#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    // unordered_map<int,int> umap;
    map<int, int> map;
    int n = grid.size();
    vector<int> res(2, -1);
    for (int i = 0; i < n; i++) {
      for (auto it : grid[i]) {
        map[it]++;
        if (map[it] == 2) res[0] = it;
      }
    }
    int count = 1;
    for (auto it : map) {
      if (it.first != count) {
        res[1] = count;
        break;
      }
      cout << it.first << endl;
      count++;
    }
    if (res[1] == -1) res[1] = count;
    // for(int i = 1; i<=n*n; i++){
    //     if(umap.find(i)==umap.end()){
    //         res[1] = i;
    //         break;
    //     }
    // }
    return res;
  }
};

int main() {



  return 0;
}