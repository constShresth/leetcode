#include <iostream>
using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0 || (x != 0 && x % 10 == 0)) return false;
    int reverse = 0;
    while (x > reverse) {
      reverse = reverse * 10 + (x % 10);
      x /= 10;
    }
    return (x == reverse) || (x == reverse / 10);
    // string n = to_string(x);
    // int i = 0, j = n.size()-1;
    // while(i<=j){
    //     if(n[i]!=n[j]) return false;
    //     i++;
    //     j--;
    // }
    // return true;
  }
};

int main() {



  return 0;
}