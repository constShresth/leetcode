#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int maxVowels(string s, int k) {
    unordered_set<char> vowels = { 'a','e','i','o','u' };
    vector<int> v(s.size(), 0);
    int res = 0;
    for (int i = 0; i < k; i++) {
      if (vowels.find(s[i]) != vowels.end()) {
        res++;
        v[i] = 1;
      }
    }
    int i = 1;
    int j = k;
    int sum = res;
    while (j < s.size()) {
      if (v[i - 1]) sum--;
      if (vowels.find(s[j]) != vowels.end()) {
        sum++;
        v[j] = 1;
      };
      res = max(res, sum);
      i++;
      j++;
    }
    return res;
  }
};

int main() {



  return 0;
}