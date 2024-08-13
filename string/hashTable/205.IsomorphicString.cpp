#include <iostream>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) {
    if(s.size()!=t.size()) return false;
    unordered_map<char,char> sMap;
    unordered_map<char,char> tMap;
    int i = 0;
    while(i<s.size()){
      if(sMap.find(s[i])!=sMap.end() && sMap[s[i]]!=t[i]) return false;
      if(tMap.find(t[i])!=tMap.end() && tMap[t[i]]!=s[i]) return false;
      sMap[s[i]]=t[i];
      tMap[t[i]]=s[i];
      i++;
    }
    return true;
  }

int main(){

  

  return 0;
}