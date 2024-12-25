#include <iostream>
#include <map>
#include <set>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> result;
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode*, pair<int, int>>> q;
    q.push({ root,{0,0} });
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      TreeNode* node = p.first;
      int x = p.second.first;
      int y = p.second.second;
      nodes[x][y].insert(node->val);
      if (node->left) q.push({ node->left,{x - 1,y + 1} });
      if (node->right) q.push({ node->right,{x + 1,y + 1} });
    }
    for (auto p : nodes) {
      vector<int> col;
      for (auto q : p.second) {
        col.insert(col.end(), q.second.begin(), q.second.end());
      }
      result.push_back(col);
    }
    return result;
    // o(n*logn), o(n)
  }
};

int main() {



  return 0;
}