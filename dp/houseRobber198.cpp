#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = 0;
        int prev2 = 0;
        for(int i = 0; i<n; i++){
            int pick = nums[i] + prev2;
            int notPick = prev;
            int curr = max(pick, notPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};

int main() {



  return 0;
}