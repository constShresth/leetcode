#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    vector<string> v;
    string result;
    int i = 0;
    while (i < s.size()) {
      string a;
      if (s[i] != ' ') {
        while (i < s.size() && s[i] != ' ') {
          a.push_back(s[i]);
          i++;
        }
        v.push_back(a);
      }      
else {
        i++;
      }
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
      result.append(v[i]);
      if (i != v.size() - 1) {
        result.push_back(' ');
      }
    }
    return result;
  }
};

int main() {



  return 0;
}