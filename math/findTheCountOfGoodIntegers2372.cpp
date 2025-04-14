#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
  long long countGoodIntegers(int n, int k) {
    unordered_set<string> s;
    int d = (n + 1) / 2; // first half of the palindrom
    int low = pow(10, d - 1); // min d digit number
    int high = pow(10, d) - 1; // max d digit number

    for (int i = low; i <= high; i++) {
      string firstHalf = to_string(i);
      string secondHalf = "";
      string full = "";
      if ((n % 2) == 0) {
        secondHalf = firstHalf;
      }
      else {
        secondHalf = firstHalf.substr(0, d - 1);
      }
      reverse(secondHalf.begin(), secondHalf.end());
      full = firstHalf + secondHalf;

      long long num = stoll(full);
      if (num % k != 0) continue;

      sort(full.begin(), full.end());
      s.insert(full);
    }

    vector<int> factorial(11, 1); // since n = 10, so we need factorial till 10;
    for (int i = 1; i < 11; i++) {
      factorial[i] = factorial[i - 1] * i;
    }
    long long res = 0;
    for (auto it : s) {
      vector<int> count(10, 0); // 0 to 9
      for (auto ch : it) {
        count[ch - '0']++;
      }

      int totalDigits = it.size();
      int zeros = count[0];
      int nonZeroDigits = totalDigits - zeros;

      long long cnt = nonZeroDigits * factorial[totalDigits - 1];
      for (int i = 0; i < 10; i++) {
        cnt /= factorial[count[i]];
      }
      res += cnt;
    }
    return res;
  }
};

int main() {



  return 0;
}