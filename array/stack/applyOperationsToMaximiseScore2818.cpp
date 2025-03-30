#include <iostream>
using namespace std;

class Solution {
private:
  long long powerMod(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
      if (exp % 2 == 1) {  // If exp is odd, multiply base with result
        result = (result * base) % mod;
      }
      base = (base * base) % mod;  // Square base
      exp /= 2;  // Reduce exponent by half
    }
    return result;
  }

public:
  int maximumScore(vector<int>& nums, int k) {
    int n = nums.size();
    long long mod = 1e9 + 7;
    long long res = 1;
    vector<int> primeScores;
    for (auto it : nums) {
      int score = 0;
      for (int i = 2; i <= sqrt(it); i++) {
        if (it % i == 0) {
          score++;
          while (it % i == 0) {
            it /= i;
          }
        }
      }
      if (it >= 2) score++;
      primeScores.push_back(score);
    }

    vector<int> leftBound(n, -1);
    vector<int> rightBound(n, n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
      while (!st.empty() && primeScores[st.top()] < primeScores[i]) {
        int ind = st.top();
        st.pop();
        rightBound[ind] = i;
      }
      if (!st.empty()) {
        leftBound[i] = st.top();
      }
      st.push(i);
    }

    priority_queue<pair<int, int>> pq; // maxHeap
    for (int i = 0; i < n; i++) {
      pq.push({ nums[i],i });
    }

    while (k > 0) {
      auto [num, ind] = pq.top();
      pq.pop();
      int score = primeScores[ind];
      int leftCnt = ind - leftBound[ind];
      int rightCnt = rightBound[ind] - ind;
      long long cnt = 1LL * leftCnt * rightCnt;
      long long operations = min(cnt, (long long)k);
      res = (res * powerMod(num, operations, mod)) % mod;
      k -= operations;
    }


    return (int)res;
  }
};

int main() {



  return 0;
}