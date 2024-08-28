#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> countBits(int n) {
    vector <int> v(n + 1, 0);
    int offset = 1;
    for (int i = 1; i <= n; i++) {
      if (i == offset * 2) offset = i;
      v[i] = 1 + v[i - offset];

      // while(num!=0){
      //     if(num==i-1){
      //         count += v[i-1];
      //         break;
      //     }
      //     if(num%2==1) count++;
      //     num /= 2;
      // }
      // v.push_back(count);
    }
    return v;
  }
};

int main() {



  return 0;
}