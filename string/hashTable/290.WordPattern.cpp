#include <iostream>
#include <unordered_map>
using namespace std;

bool wordPattern(string pattern, string s) {
    int j = 0;
    int count = 0;
    while(j<s.size()){
      if(s[j]==' '){
        count++;
      };
      j++;
    }
    if(count!=pattern.size()-1) return false;
    unordered_map<char,string> pToS;
    unordered_map<string,char> sToP;
    int i = 0;
    j = 0;
    while(i<pattern.size()){
      string str = "";
      while(j<s.size()){
        if(s[j]==' '){
          j++;
          break;
        };
        str.push_back(s[j]);
        j++;
      }
      if(pToS.find(pattern[i])!=pToS.end() && pToS[pattern[i]]!=str) return false;
      if(sToP.find(str)!=sToP.end() && sToP[str]!=pattern[i]) return false;
      pToS[pattern[i]]=str;
      sToP[str]=pattern[i];
      i++;
    }
    return true;
  }

int main(){

  

  return 0;
}