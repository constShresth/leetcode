#include <iostream>
using namespace std;

class Solution {
public:
  int maxRepeating(string sequence, string word) {
    int k = 0;
    string a = word;
    while (sequence.find(a) != string::npos) {
      k++;
      a += word;
    }
    return k;
  }
};

int main() {



  return 0;
}