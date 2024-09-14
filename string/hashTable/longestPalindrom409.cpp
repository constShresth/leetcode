#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int longestPalindrome(string s) {
    unordered_map<int, int> umap;
    int count = 0;
    bool flag = true;
    for (auto c : s) {
      umap[c]++;
    }
    for (auto pair : umap) {
      if (pair.second % 2 == 0) {
        count += pair.second;
      }
      else {
        count = count + pair.second - 1;
        if (flag) {
          count += 1;
          flag = false;
        }
      }
    }
    return count;
  }
};

int main() {



  return 0;
}