#include <iostream>
using namespace std;

class Solution {
public:
  long long countGood(vector<int>& nums, int k) {
    int n = nums.size();
    // unordered_map<int,int> umap;
    unordered_map<int, int> freq;
    long long res = 0;
    int cnt = 0;
    int i = 0, j = 0;
    while (i < n) {
      cnt += freq[nums[i]];
      freq[nums[i]]++;
      while (cnt >= k) {
        res += n - i;
        freq[nums[j]]--;
        cnt -= freq[nums[j]];
        j++;
      }
      // if(cnt>=k){
      //     res += n-i;
      //     while(j<i){
      //         freq[nums[j]]--;
      //         cnt -= freq[nums[j]];
      //         j++;
      //         if(cnt>=k) res += n-i;
      //         else break;
      //     }
      // }
      i++;
    }
    return res;
    // while(i<n){
    //     if(umap[nums[i]]>=2){
    //         int count = umap[nums[i]];
    //         int val = count*(count-1)/2;
    //         cnt -= val;
    //     }
    //     umap[nums[i]]++;
    //     if(umap[nums[i]]>=2){
    //         int count = umap[nums[i]];
    //         int val = count*(count-1)/2;
    //         cnt += val;
    //     } 
    //     if(cnt>=k){
    //         res += n-i;
    //         while(j<i){
    //             if(umap[nums[j]]>=2){
    //                 int count = umap[nums[j]];
    //                 int val = count*(count-1)/2;
    //                 cnt -= val;
    //             }
    //             umap[nums[j]]--;
    //             if(umap[nums[j]]>=2){
    //                 int count = umap[nums[j]];
    //                 int val = count*(count-1)/2;
    //                 cnt += val;
    //             } 
    //             j++;
    //             if(cnt>=k) res += n-i;
    //             else break;
    //         }
    //     }
    //     i++;
    // }
    // return res;
  }
};

int main() {



  return 0;
}