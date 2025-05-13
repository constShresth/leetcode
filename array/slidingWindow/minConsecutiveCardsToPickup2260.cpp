#include <iostream>
using namespace std;

class Solution {
public:
  int minimumCardPickup(vector<int>& cards) {
    int n = cards.size();
    int l = 0, r = 0, res = INT_MAX;
    unordered_map<int, int> umap;
    while (r < n) {
      if (umap.count(cards[r])) {
        int lastIndex = umap[cards[r]];
        res = min(res, r - lastIndex + 1);
      }
      umap[cards[r]] = r;
      r++;
    }
    return res == INT_MAX ? -1 : res;
    // while(r<n){
    //     umap[cards[r]]++;
    //     bool flag = false;
    //     while(umap[cards[r]]>1){
    //         flag = true;
    //         umap[cards[l]]--;
    //         l++;
    //     }
    //     if(flag) res = min(res,r-l+2);
    //     r++;
    // }
    // return res==INT_MAX ? -1:res;
  }
};

int main() {



  return 0;
}