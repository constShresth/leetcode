#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int compress(vector<char>& chars) {
    int i = 0;
    int count = 0;
    int res = i;
    while (i < chars.size()) {
      if (count == 0) {
        count++;
        chars[res] = chars[i];
        i++;
        res++;
      }
      else {
        int j = i;
        while (j < chars.size() && chars[j] == chars[j - 1]) {
          count++;
          j++;
        }
        if (count > 1) {
          vector<int> v;
          while (count) {
            v.push_back(count % 10);
            count /= 10;
          }
          reverse(v.begin(), v.end());
          for (int num : v) {
            chars[res] = '0' + num;
            i++;
            res++;
          }
        }
        count = 0;
        i = j;
      }
    }
    return res;
  }
};

int main() {



  return 0;
}