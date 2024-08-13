#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char,int> ransomLetterCount;
    unordered_map<char,int> magazineLetterCount;
    for(int i = 0; i<ransomNote.size(); i++){
      ransomLetterCount[ransomNote[i]]++;
    }
    for(int i = 0; i<magazine.size(); i++){
      magazineLetterCount[magazine[i]]++;
    }
    for(auto pair:ransomLetterCount){
      if(magazineLetterCount.find(pair.first)==magazineLetterCount.end()){
        return false;
      }
      if(pair.second>magazineLetterCount[pair.first]){
        return false;
      }
    }
    return true;
  }
};

int main(){

  

  return 0;
}