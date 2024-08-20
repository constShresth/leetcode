#include <iostream>
#include <vector>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
  vector<string> ans;
  int i = 0;
  int j = 0;
  while(i<nums.size()){
    while(i<nums.size()-1 && nums[i+1]==nums[i]+1){
      i++;
    }
    if(i!=j){
      ans.push_back(to_string(nums[j])+"->"+to_string(nums[i]));
    }else{
      ans.push_back(to_string(nums[j]));
    }
    i++;
    j=i;
  }
  return ans;
}

int main(){

  

  return 0;
}