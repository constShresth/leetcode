#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector <vector<string>> v;
    unordered_map <string, vector<string>> umap;
    for (auto str : strs) {
      string temp = str;
      sort(str.begin(), str.end());
      umap[str].push_back(temp);
    }
    for (auto pair : umap) {
      v.push_back(pair.second);
    }
    return v;
  }
};

int main() {



  return 0;
}