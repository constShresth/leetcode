#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool uniqueOccurrences(vector<int>& arr) {
    unordered_map <int, int> map1;
    unordered_map <int, int> map2;
    for (const auto num : arr) {
      map1[num]++;
    }
    for (const auto pair : map1) {
      map2[pair.second]++;
      if (map2[pair.second] > 1) {
        return false;
      }
    }
    return true;
  }
};

int main() {



  return 0;
}