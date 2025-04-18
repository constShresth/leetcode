#include <iostream>
using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

    int left = (n1 + n2) / 2;
    int low = 0, high = min(n1, left);

    while (low <= high) {
      int mid1 = low + (high - low) / 2;
      int mid2 = left - mid1;

      int l1 = INT_MIN, l2 = INT_MIN;
      int r1 = INT_MAX, r2 = INT_MAX;

      if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
      if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];
      if (mid1 < n1) r1 = nums1[mid1];
      if (mid2 < n2) r2 = nums2[mid2];

      if (l1 > r2) high = mid1 - 1;
      else if (l2 > r1) low = mid1 + 1;
      else {
        double median;
        if ((n1 + n2) % 2 == 0) {
          median = (max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else {
          median = min(r1, r2);
        }
        return median;
      }
    }
    return -1;
    // o(min(log(n1),log(n2)))


    // vector<int> nums;
    // int i = 0; 
    // int j = 0;
    // int n1 = nums1.size(), n2 = nums2.size();
    // int n = n1 + n2;
    // int ind1 = n/2;
    // int ind2 = (n/2) - 1;
    // int cnt = 0;
    // int el1,el2;
    // while(i<n1 && j<n2){
    //     if(nums1[i]<=nums2[j]){
    //         if(cnt==ind1) el1 = nums1[i];
    //         else if(cnt==ind2) el2 = nums1[i];
    //         cnt++;
    //         i++;
    //     }
    //     else{
    //         if(cnt==ind1) el1 = nums2[j];
    //         else if(cnt==ind2) el2 = nums2[j];
    //         cnt++;
    //         j++;
    //     }
    // }
    // while(i<n1){
    //     if(cnt==ind1) el1 = nums1[i];
    //     else if(cnt==ind2) el2 = nums1[i];
    //     cnt++;
    //     i++;
    // }
    // while(j<n2){
    //     if(cnt==ind1) el1 = nums2[j];
    //     else if(cnt==ind2) el2 = nums2[j];
    //     cnt++;
    //     j++;
    // }
    // if(n%2 == 1) return el1;
    // else return (el1+el2)/2.0;
    // o(n1+n2)

    // while(i<n1 && j<n2){
    //     if(nums1[i]<=nums2[j]) nums.push_back(nums1[i++]);
    //     else nums.push_back(nums2[j++]);
    // }
    // while(i<n1) nums.push_back(nums1[i++]);
    // while(j<n2) nums.push_back(nums2[j++]);
    // int n = n1 + n2;
    // if(n%2 == 1) return nums[n/2];
    // return (nums[n/2] + nums[(n/2)-1]) / 2.0;
    // o(n1+n2)
  }
};

int main() {



  return 0;
}