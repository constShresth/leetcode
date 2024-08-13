#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
  unordered_map<int,int> umap;
  int i = 0;
  while(i<nums.size()){
    if(umap.find(nums[i])!=umap.end()){
      if(abs(umap[nums[i]]-i)<=k) return true;
    }
    umap[nums[i]]=i;
    i++;
  }
  return false;
}

int main(){



  return 0;
}