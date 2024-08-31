#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int firstUniqChar(string s) {
    unordered_map <char, int> umap;
    for (auto c : s) {
      umap[c]++;
    }
    for (int i = 0; i < s.size(); i++) {
      if (umap[s[i]] == 1) return i;
    }
    return -1;
  }
};

int main() {



  return 0;
}