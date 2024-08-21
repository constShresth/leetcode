#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedSet {
public:
  vector <int> v;
  unordered_map<int, int> umap;
  RandomizedSet() {
  }

  bool insert(int val) {
    if (umap.find(val) != umap.end()) {
      return false;
    }
    else {
      v.push_back(val);
      umap[val] = v.size() - 1;
      return true;
    }
  }

  bool remove(int val) {
    if (umap.find(val) != umap.end()) {
      int index = umap[val];
      umap[v[v.size() - 1]] = index;
      umap.erase(val);
      v[index] = v[v.size() - 1];
      v.erase(v.begin() + (v.size() - 1));
      return true;
    }
    else {
      return false;
    }
  }

  int getRandom() {
    return v[0 + (rand() % ((v.size() - 1) - 0 + 1))];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {



  return 0;
}