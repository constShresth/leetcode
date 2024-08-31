#include <iostream>
using namespace std;

class Solution {
public:
  string removeStars(string s) {
    int i = 0;
    for (auto c : s) {
      if (c != '*') {
        s[i] = c;
        i++;
      }
      else {
        i--;
      }
    }
    return s.substr(0, i);

    // string res;
    // for(int i = 0; i<s.size(); i++){
    //     if(s[i]=='*'){
    //         res.pop_back();
    //     }else{
    //         res.push_back(s[i]);
    //     }
    // }
    // return res;
  }
};

int main() {



  return 0;
}