#include <iostream>
using namespace std;

class Solution {
public:
  int secondHighest(string s) {
    int largest = -1;
    int sLargest = -1;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (s[i] >= '0' && s[i] <= '9') {
        int num = s[i] - '0';
        if (num > largest) {
          sLargest = largest;
          largest = num;
        }
        else if (num > sLargest && num < largest) {
          sLargest = num;
        }
      }
    }
    return sLargest;
  }
};

int main() {



  return 0;
}