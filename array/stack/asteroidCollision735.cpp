#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    stack <int> st;
    vector<int> res;
    for (auto ast : asteroids) {
      int alive = true;
      while (alive && !st.empty() && st.top() > 0 && ast < 0) {
        int prev = st.top();
        if (abs(ast) > prev) st.pop();
        else if (abs(ast) == prev) {
          st.pop();
          alive = false;
        }
        else alive = false;
      }
      if (alive) st.push(ast);
    }
    while (!st.empty()) {
      res.insert(res.begin(), st.top());
      st.pop();
    }
    return res;
  }
};

int main() {



  return 0;
}