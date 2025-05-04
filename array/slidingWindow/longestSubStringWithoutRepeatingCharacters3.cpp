#include <iostream>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int l = 0, r = 0;
    int ans = 0;
    unordered_map<char, int> umap;
    vector<int> hash(128, -1);
    while (r < n) {
      if (hash[s[r]] != -1 && hash[s[r]] >= l) {
        l = hash[s[r]] + 1;
      }
      hash[s[r]] = r;
      ans = max(ans, r - l + 1);
      r++;
    }
    // while(r<n){
    //     umap[s[r]]++;
    //     while(umap[s[r]]>1){
    //         umap[s[l]]--;
    //         l++;
    //     }
    //     ans = max(ans,r-l+1);
    //     r++;
    // }
    return ans;
  }
};

int main() {



  return 0;
}