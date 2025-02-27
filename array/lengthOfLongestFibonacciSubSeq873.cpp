#include <iostream>
using namespace std;

class Solution {
private:
  int bs(int l, int r, vector<int>& arr, int target) {
    while (l <= r) {
      int mid = l + ((r - l) / 2);
      if (arr[mid] == target) {
        return mid;
      }
      else if (arr[mid] > target) {
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }
    return -1;
  }
  int f(int i, int j, vector<int>& arr) {
    int next = arr[i] + arr[j];
    int n = arr.size();
    int index = bs(j + 1, n - 1, arr, next);
    if (index != -1) {
      return 1 + f(j, index, arr);
    }
    return 0;
  }

public:
  int lenLongestFibSubseq(vector<int>& arr) {
    int n = arr.size();
    int maxLen = 0;
    unordered_map<int, int> umap;
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        maxLen = max(maxLen, 2 + f(i, j, arr));
      }
    }

    return maxLen >= 3 ? maxLen : 0;

  }
};

int main() {



  return 0;
}