#include <iostream>
using namespace std;

class Solution {
public:
  int characterReplacement(string s, int k) {
    int n = s.size();
    int l = 0, r = 0, ans = 0;
    unordered_map<char, int> umap;
    int maxF = 0;
    while (r < n) {
      umap[s[r]]++;
      maxF = max(maxF, umap[s[r]]);
      if ((r - l + 1) - maxF > k) {
        umap[s[l]]--;
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