#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int greatest = 0;
    vector <bool> vec;
    for (auto candy : candies) greatest = max(greatest, candy);
    for (auto candy : candies) vec.push_back(candy + extraCandies >= greatest);
    return vec;
  }
};

int main() {



  return 0;
}