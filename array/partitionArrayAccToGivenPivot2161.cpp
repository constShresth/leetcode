#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector<int> more;
    vector<int> res;

    for (auto it : nums) {
      if (it < pivot) res.push_back(it);
      if (it > pivot) more.push_back(it);
    }
    for (auto it : nums) {
      if (it == pivot) res.push_back(it);
    }
    for (auto it : more) {
      res.push_back(it);
    }

    return res;

  }
};

int main() {



  return 0;
}