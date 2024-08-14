#include <iostream>
using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    string ans;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    while (i >= 0 && j >= 0) {
      if (a[i] == '1' && b[j] == '1') {
        if (carry == 1) {
          ans = '1' + ans;
          carry = 1;
        }
        else {
          ans = '0' + ans;
          carry = 1;
        }

      }
      else if (a[i] == '0' && b[j] == '0') {
        if (carry == 1) {
          ans = '1' + ans;
          carry = 0;
        }
        else {
          ans = '0' + ans;
        }
      }
      else {
        if (carry == 1) {
          ans = '0' + ans;
        }
        else {
          ans = '1' + ans;
        }
      }
      i--;
      j--;
    }
    while (i >= 0) {
      if (a[i] == '1') {
        if (carry == 1) {
          ans = '0' + ans;
        }
        else {
          ans = '1' + ans;
        }
      }
      else {
        if (carry == 1) {
          ans = '1' + ans;
          carry = 0;
        }
        else {
          ans = '0' + ans;
        }
      }
      i--;
    }
    while (j >= 0) {
      if (b[j] == '1') {
        if (carry == 1) {
          ans = '0' + ans;
        }
        else {
          ans = '1' + ans;
        }
      }
      else {
        if (carry == 1) {
          ans = '1' + ans;
          carry = 0;
        }
        else {
          ans = '0' + ans;
        }
      }
      j--;
    }
    if (carry == 1) {
      ans = '1' + ans;
    }
    return ans;
  }
};

int main() {



  return 0;
}