#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
private:
  long long atLeastK(string word, int k) {
    unordered_map<char, int> umap;
    int consonant = 0;
    long long res = 0;
    int l = 0;
    int n = word.size();
    static const unordered_set<char> vowels = { 'a','e','i','o','u' };
    for (int r = 0; r < n; r++) {
      if (vowels.count(word[r])) {
        umap[word[r]]++;
      }
      else {
        consonant++;
      }

      while (umap.size() == 5 && consonant >= k) {
        res += n - r;
        if (vowels.count(word[l])) {
          umap[word[l]]--;
        }
        else {
          consonant--;
        }
        if (umap[word[l]] == 0) {
          umap.erase(word[l]);
        }
        l++;
      }
    }
    return res;
  }
public:
  long long countOfSubstrings(string word, int k) {
    return atLeastK(word, k) - atLeastK(word, k + 1);
  }
};

int main() {



  return 0;
}