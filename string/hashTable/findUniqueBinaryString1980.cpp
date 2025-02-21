#include <iostream>
using namespace std;

class Solution {
public:
  string findDifferentBinaryString(vector<string>& nums) {
    int n = nums.size();
    unordered_map<string, int> umap;
    string s = "";
    for (int i = 0; i < n; i++) {
      s.push_back('0');
    }
    umap[s] = 1;
    int index = 0;
    for (int i = 0; i < n; i++) {
      s[i] = '1';
      umap[s] = 1;
      s[i] = '0';
      index++;
    }
    for (auto it : nums) {
      if (umap[it] == 1) {
        umap[it] = 0;
      }
    }
    for (auto it : umap) {
      if (it.second == 1) return it.first;
    }
    return "";
  }
};

int main() {



  return 0;
}