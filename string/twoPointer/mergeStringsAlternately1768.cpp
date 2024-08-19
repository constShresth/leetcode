#include <iostream>
using namespace std;

class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    int i = 0;
    string res;
    while (i < word1.size() && i < word2.size()) {
      res.push_back(word1[i]);
      res.push_back(word2[i]);
      i++;
    }
    while (i < word1.size()) {
      res.push_back(word1[i]);
      i++;
    }
    while (i < word2.size()) {
      res.push_back(word2[i]);
      i++;
    }
    return res;
  }
};

int main() {

  return 0;
}