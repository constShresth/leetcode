#include <iostream>
using namespace std;

class Solution {
public:
  int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int missingNums = arr[mid] - (mid + 1);
      if (missingNums < k) {
        low = mid + 1;
      }
      else {
        high = mid - 1;
      }
    }
    // int missingNums = arr[high] - (high+1);
    // int more = k - missingNums;
    // return arr[high] + more;
    // since high might point to -1 if missing number is less than arr[0]
    // so we will solve the above equation
    // after solving => high + 1 + k => low + k;
    return low + k;


    // int num = k;
    // for(int i = 0; i<n; i++){
    //     if(arr[i]<=num){
    //         num++;
    //     }else break;
    // }
    // return num;


    // int num = 0;
    // int cnt = 0;
    // int i = 0;
    // while(i<n){
    //     num++;
    //     if(arr[i]==num){
    //         i++;
    //     }else{
    //         cnt++;
    //     }
    //     if(cnt==k) return num;
    // }
    // while(cnt<k){
    //     num++;
    //     cnt++;
    // }
    // return num;
  }
};

int main() {



  return 0;
}