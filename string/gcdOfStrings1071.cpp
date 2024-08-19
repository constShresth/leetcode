#include <iostream>
using namespace std;

class Solution {
public:
  // string repeat(string substr, int f){
  //     string result;
  //     for(int i = 0; i<f; i++){
  //         result += substr;
  //     }
  //     return result;
  // }
  // bool isDivisor(int l, int l1, int l2, string str1, string str2){
  //     if(l1%l!=0 || l2%l!=0) return false;
  //     int f1 = l1/l, f2 = l2/l;
  //     return repeat(str1.substr(0,l),f1)==str1 && repeat(str1.substr(0,l),f2)==str2;
  // }

  int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  string gcdOfStrings(string str1, string str2) {
    if (str1 + str2 != str2 + str1) return "";
    int gcdLength = gcd(str1.size(), str2.size());
    return str1.substr(0, gcdLength);
    // int l1 = str1.size();
    // int l2 = str2.size();
    // for(int i = min(l1,l2); i>0; i--){
    //     if(isDivisor(i, l1, l2, str1, str2)) return str1.substr(0,i);
    // }
    // return "";
  }
};

int main() {



  return 0;
}