#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  // for(int i=0;i<nums.size()-1;i++){
  //     for(int j=i+1; j<nums.size();j++){
  //         if(nums[i]+nums[j]==target){
  //             return {i,j};
  //         };
  //     };
  // };
  // return {};
  
  vector <pair<int,int>> vec;
  for(int i=0; i<nums.size(); i++){
    vec.push_back({nums[i],i});
  }
  sort(vec.begin(),vec.end());
  int left = 0;
  int right = nums.size()-1;
  while(left<right){
    int sum = vec[left].first+vec[right].first;
    if(sum==target){
      return {vec[left].second,vec[right].second};
    }else if(sum<target){
      left++;
    }else{
      right--;
    }
  }
  return {};
};

int main(){

  

  return 0;
}