#include <iostream>
using namespace std;

class Solution {
public:
  int reverse(int x) {
    long long result = 0;
    while (x) {
      int digit = x % 10;
      result = result * 10 + digit;
      x /= 10;
    }
    if (result > INT_MAX || result < INT_MIN) return 0;
    return result;
    // vector<int> digits;
    // while(x!=0){
    //     int k = x%10;
    //     digits.push_back(k);
    //     x = x/10;
    // } 
    // for(int i = 0; i<digits.size(); i++){
    //     if((digits[i]>=0 && (x<=(INT_MAX-digits[i])/10)) || (digits[i]<0 && (x>=(INT_MIN-digits[i])/10) )){
    //         x = (x * 10 )+ digits[i]; 
    //     }else{
    //         return 0;
    //     }
    // }
    // return x;
  }
};

int main() {



  return 0;
}