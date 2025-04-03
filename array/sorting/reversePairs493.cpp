#include <iostream>
using namespace std;

class Solution {
private:
  int countPairs(vector<int>& nums, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++) {
      while (right <= high && nums[i] > (long long)2 * nums[right]) {
        right++;
      }
      cnt += (right - (mid + 1));
    }
    return cnt;
  }
  void merge(vector<int>& nums, int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    vector<int> temp;
    while (left <= mid && right <= high) {
      if (nums[left] <= nums[right]) temp.push_back(nums[left++]);
      else temp.push_back(nums[right++]);
    }
    while (left <= mid) temp.push_back(nums[left++]);
    while (right <= high) temp.push_back(nums[right++]);
    for (int i = low; i <= high; i++) nums[i] = temp[i - low];
  }
  int mergeSort(vector<int>& nums, int low, int high) {
    int res = 0;
    if (low >= high) return res;
    int mid = low + (high - low) / 2;
    res += mergeSort(nums, low, mid);
    res += mergeSort(nums, mid + 1, high);
    res += countPairs(nums, low, mid, high);
    merge(nums, low, mid, high);
    return res;
  }
public:
  int reversePairs(vector<int>& nums) {
    int n = nums.size();
    return mergeSort(nums, 0, n - 1);
    // o(2n*log(n)), o(n)
  }
};

int main() {



  return 0;
}