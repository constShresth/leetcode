#include <iostream>
using namespace std;

class Solution {
public:
  char findTheDifference(string s, string t) {
    char result = 0;
    for (char c : s) {
      result ^= c;
    }
    for (char c : t) {
      result ^= c;
    }
    return result;
    // cout<<result<<endl;
    // unordered_map <char,int> umap;
    // for(auto c:s){
    //     umap[c]++;
    // }
    // for(auto c:t){
    //     umap[c]--;
    // }
    // for(auto pair:umap){
    //     if(pair.second!=0) return pair.first;
    // }
    // return 'a';
  }
};

int main() {



  return 0;
}