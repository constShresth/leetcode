#include <iostream>
using namespace std;

class Solution {
public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int n1 = g.size();
    int n2 = s.size();
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
      if (s[j] >= g[i]) {
        j++;
        i++;
      }
      else {
        j++;
      }
    }
    return i;
  }
};

int main() {



  return 0;
}