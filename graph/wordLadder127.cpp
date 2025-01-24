#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<pair<string, int>> q;
    q.push({ beginWord,1 });
    st.erase(beginWord);
    while (!q.empty()) {
      string word = q.front().first;
      int steps = q.front().second;
      q.pop();
      if (word == endWord) return steps;
      for (int i = 0; i < word.size(); i++) {
        for (char ch = 'a'; ch <= 'z';ch++) {
          string newWord = word;
          newWord[i] = ch;
          if (st.find(newWord) != st.end()) {
            st.erase(newWord);
            q.push({ newWord,steps + 1 });
          }
        }
      }
    }
    return 0;
  }
};

int main() {



  return 0;
}