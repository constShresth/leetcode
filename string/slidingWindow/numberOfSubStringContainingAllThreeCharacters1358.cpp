#include <iostream>
using namespace std;

class Solution {
public:
  int numberOfSubstrings(string s) {
    int n = s.size();
    int l = 0;
    int res = 0;
    unordered_map<char, int> umap;
    for (int r = 0; r < n; r++) {
      if (s[r] == 'a' || s[r] == 'b' || s[r] == 'c') {
        umap[s[r]]++;
      }
      while (umap.size() == 3) {
        res += n - r;
        if (s[l] == 'a' || s[l] == 'b' || s[l] == 'c') {
          umap[s[l]]--;
        }
        if (umap[s[l]] == 0) {
          umap.erase(s[l]);
        }
        l++;
      }
    }
    return res;
  }
};

int main() {



  return 0;
}