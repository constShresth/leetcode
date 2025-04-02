#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> partitionLabels(string s) {
    int n = s.size();
    vector<int> res;
    unordered_map<char, int> umap;
    for (int i = 0; i < n; i++) {
      umap[s[i]] = i;
    }
    int i = 0;
    while (i < n) {
      char x = s[i];
      int firstIndex = i;
      int lastIndex = umap[x];
      while (i <= lastIndex) {
        x = s[i];
        if (umap[x] > lastIndex) {
          lastIndex = umap[x];
        }
        i++;
      }
      res.push_back(lastIndex - firstIndex + 1);
    }
    return res;
  }
};

int main() {



  return 0;
}