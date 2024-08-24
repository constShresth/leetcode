#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int count = 0;
    int prev = 0;
    int i = 0;
    while (i < flowerbed.size() - 1) {
      if (prev == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
        count++;
        flowerbed[i] = 1;
      }
      prev = flowerbed[i];
      i++;
    }
    if (prev == 0 && flowerbed[i] == 0) {
      count++;
      flowerbed[i] == 1;
    }
    return count >= n;
  }
};

int main() {



  return 0;
}