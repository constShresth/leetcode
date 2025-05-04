#include <iostream>
using namespace std;

class Solution {
public:
  int totalFruit(vector<int>& fruits) {
    int n = fruits.size();
    unordered_map<int, int> umap;
    int l = 0, r = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      umap[fruits[i]]++;
      if (umap.size() > 2) {
        umap[fruits[l]]--;
        if (umap[fruits[l]] == 0) umap.erase(fruits[l]);
        l++;
      }
      ans = max(ans, r - l + 1);
      r++;
    }
    return ans;
  }
};

int main() {



  return 0;
}