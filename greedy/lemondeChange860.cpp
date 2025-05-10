#include <iostream>
using namespace std;

class Solution {
public:
  bool lemonadeChange(vector<int>& bills) {
    int n = bills.size();
    int five = 0, ten = 0;
    for (int i = 0; i < n; i++) {
      if (bills[i] == 5) five++;
      else if (bills[i] == 10) {
        if (five > 0) {
          five--;
          ten++;
        }
        else return false;
      }
      else {
        if (ten > 0 && five > 0) {
          ten--;
          five--;
        }
        else if (five >= 3) five -= 3;
        else return false;
      }
    }
    return true;
    //     unordered_map<int,int> umap;
    //     for(int i = 0; i<n; i++){
    //         int change = bills[i] - 5;
    //         umap[bills[i]]++;
    //         if(change == 0) continue;
    //         if(change == 5){
    //             if(umap[change]==0) return false;
    //             else umap[change]--;
    //         }
    //         if(change == 15){
    //             if((umap[5] == 0) || (umap[10]==0 && umap[5]<3)) return false;
    //             else{
    //                 if(umap[10]==0) umap[5] -= 3;
    //                 else{
    //                 umap[10]--;
    //                 umap[5]--;
    //                 }
    //             }
    //         }
    //     }
    //     return true;
  }
};

int main() {



  return 0;
}