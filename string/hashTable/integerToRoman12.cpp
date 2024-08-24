#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  string intToRoman(int num) {
    vector<int> nums;
    string result;
    while (num != 0) {
      int digit = num % 10;
      nums.insert(nums.begin(), digit);
      num /= 10;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (nums.size() - i == 4) {
        result.append(nums[i], 'M');
      }
      else if (nums.size() - i == 3) {
        if (nums[i] < 5) {
          if (nums[i] == 4) {
            result.append("CD");
          }
          else {
            result.append(nums[i], 'C');
          }
        }
        else {
          if (nums[i] == 9) {
            result.append("CM");
          }          
else {
            result.push_back('D');
            result.append(nums[i] - 5, 'C');
          }
        }
      }
      else if (nums.size() - i == 2) {
        if (nums[i] < 5) {
          if (nums[i] == 4) {
            result.append("XL");
          }
          else {
            result.append(nums[i], 'X');
          }
        }
        else {
          if (nums[i] == 9) {
            result.append("XC");
          }
          else {
            result.push_back('L');
            result.append(nums[i] - 5, 'X');
          }
        }
      }
      else if (nums.size() - i == 1) {
        if (nums[i] < 5) {
          if (nums[i] == 4) {
            result.append("IV");
          }
          else {
            result.append(nums[i], 'I');
          }
        }
        else {
          if (nums[i] == 9) {
            result.append("IX");
          }
          else {
            result.push_back('V');
            result.append(nums[i] - 5, 'I');
          }
        }
      }

    }
    return result;
  }
};

int main() {



  return 0;
}