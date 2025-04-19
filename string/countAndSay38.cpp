#include <iostream>
using namespace std;

class Solution {
private:
  string rle(string s) {
    int n = s.size();
    string res = "";
    int i = 0;
    while (i < n) {
      int cnt = 0;
      while (i < n - 1 && s[i] == s[i + 1]) {
        i++;
        cnt++;
      }
      cnt++;
      res.push_back((cnt + '0'));
      res.push_back(s[i]);
      i++;
    }
    return res;
  }
public:
  string countAndSay(int n) {
    if (n == 1) return "1";
    string s = countAndSay(n - 1);
    return rle(s);
  }
};

int main() {



  return 0;
}