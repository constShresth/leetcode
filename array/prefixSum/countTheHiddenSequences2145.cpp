#include <iostream>
using namespace std;

class Solution {
public:
  int numberOfArrays(vector<int>& differences, int lower, int upper) {
    int n = differences.size();
    int minVal = 0, maxVal = 0;
    int curr = 0;
    for (int i = 0; i < n; i++) {
      curr = curr + differences[i];
      minVal = min(minVal, curr);
      maxVal = max(maxVal, curr);

      if (((upper - maxVal) - (lower - minVal) + 1) <= 0) return 0;
    }

    return (upper - maxVal) - (lower - minVal) + 1;


    // for(int i = lower; i<=upper; i++){
    //     bool flag = true;
    //     int num = i;
    //     for(int j = 0; j<n; j++){
    //         num = num + differences[j];
    //         if(num>upper || num<lower) flag = false;
    //     }
    //     if(flag) cnt++;
    // }
    // return cnt;
    // tle
  }
};

int main() {



  return 0;
}