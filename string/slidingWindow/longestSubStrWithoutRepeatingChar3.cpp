#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map <char, int> umap;
    int result = INT_MIN;
    int l = 0;
    int r = 0;
    while (r < s.size()) {
      umap[s[r]]++;
      if (umap[s[r]] > 1) {
        for (int i = r - 1; i >= l; i--) {
          if (s[i] == s[r]) {
            l = i + 1;
            umap[s[r]]--;
          }
        }
      }
      result = max(result, (r - l + 1));
      r++;
    }
    return result == INT_MIN ? 0 : result;
  }
};

int main() {



  return 0;
}