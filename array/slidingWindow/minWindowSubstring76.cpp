#include <iostream>
using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    int n = s.size();
    unordered_map<char, int> umap;
    for (auto ch : t) {
      umap[ch]++;
    }
    int m = umap.size();
    int l = 0, r = 0, cnt = 0, len = INT_MAX, startIndex = -1;
    while (r < n) {
      umap[s[r]]--;
      if (umap[s[r]] == 0) cnt++;
      while (cnt == m) {
        int currLen = r - l + 1;
        if (currLen < len) {
          len = currLen;
          startIndex = l;
        }
        umap[s[l]]++;
        if (umap[s[l]] > 0) cnt--;
        l++;
      }
      r++;
    }
    return startIndex == -1 ? "" : s.substr(startIndex, len);
  }
};

int main() {



  return 0;
}