#include <iostream>
using namespace std;

class Solution {
public:
  int partitionString(string s) {
    int n = s.size();
    int l = 0, r = 0, cnt = 1;
    vector<int> hash(128, -1);
    // we can reduce the space as it contain's only lowercase english letters
    while (r < n) {
      if (hash[s[r]] != -1 && hash[s[r]] >= l) {
        cnt++;
        l = r;
      }
      hash[s[r]] = r;
      r++;
    }
    return cnt;
  }
};

int main() {



  return 0;
}