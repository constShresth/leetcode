#include <iostream>
using namespace std;

class Solution{
public:
  bool isSubsequence(string s, string t){
    int i = 0;
    int j = 0;
    if (s == "") return true;
    if (t == "") return false;

    while (i < s.size() && j < t.size()){
      if (s[i] == t[j]){
        i++;
      }
      if (i == s.size()){
        return true;
      }
      j++;
    }
    return false;
  }
};