#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int hIndex(vector<int>& citations) {
    int n = citations.size() - 1;
    int count = 0;
    int hIndex = citations.size();
    sort(citations.begin(), citations.end());
    while (hIndex > 0 && n >= 0) {
      if (citations[n] >= hIndex) {
        count++;
        n--;
      }
      else {
        hIndex--;
      }
      if (count >= hIndex) return hIndex;
    }
    return hIndex;
  }

  // int hIndex(vector<int>& citations) {
  //   int n = citations.size();
  //   sort(citations.begin(), citations.end());
  //   for (int i = 0;i < n;i++) if ((n - i) <= citations[i]) return (n - i);
  //   return 0;
  // }
};

int main() {



  return 0;
}