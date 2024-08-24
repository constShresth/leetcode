#include <iostream>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
  //1
  // if(s.size()!=t.size()) return false;
  // unordered_map<char,int> sMap;
  // unordered_map<char,int> tMap;
  // int i = 0;
  // while(i<s.size()){
  //   sMap[s[i]]++;
  //   tMap[t[i]]++;
  //   i++;
  // }
  // i=0;
  // while(i<s.size()){
  //   if(sMap[s[i]]!=tMap[s[i]]) return false;
  //   i++;
  // }
  // return true;

  //2
  // if(s.size()!=t.size()) return false;
  // sort(s.begin(), s.end());
  // sort(t.begin(), t.end());
  // return s==t;

  //3
  if(s.size()!=t.size()) return false;
  int freq[26]={0};
  for(int i=0; i<s.size();i++){
    freq[s[i]-97]++;
  }
  for(int i=0; i<t.size();i++){
    freq[t[i]-97]--;
  }
  for(int i=0; i<26; i++){
    if(freq[i]>0) return false;
  }
  return true;

}

int main(){

  

  return 0;
}