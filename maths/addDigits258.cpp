#include <iostream>
using namespace std;

class Solution {
public:
  int addDigits(int num) {
    if (num == 0) return 0;
    return num % 9 == 0 ? 9 : num % 9;
    // if(num<=9) return num;
    // int sum = 0;
    // while(num!=0){
    //     int digit = num%10;
    //     sum += digit;
    //     num /= 10;
    // }
    // return addDigits(sum);
  }
};

int main() {



  return 0;
}