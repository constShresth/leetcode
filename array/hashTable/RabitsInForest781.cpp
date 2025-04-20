#include <iostream>
using namespace std;

class Solution {
public:
  int numRabbits(vector<int>& answers) {
    int n = answers.size();
    unordered_map<int, int> umap;
    int res = 0;
    for (int x : answers) {
      umap[x]++;
    }
    for (auto pair : umap) {
      int x = pair.first;
      int cnt = pair.second;
      int groupSize = (x + 1);
      int groups = ceil((double)cnt / groupSize);

      res += (groups * groupSize);
    }
    return res;

    // for(int i = 0; i<n; i++){
    //     if(answers[i] == 0) res++;
    //     else if(umap[answers[i]] == answers[i]+1){
    //         res += (answers[i] + 1);
    //         umap[answers[i]] = 1;
    //     }
    //     else umap[answers[i]]++;
    // }
    // for(auto pairs:umap){
    //     res += (pairs.first + 1);
    // }
    // return res;
  }
};

int main() {



  return 0;
}