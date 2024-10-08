#include <iostream>
#include <vector>
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
  void dfs(TreeNode* root, vector<int>& v) {
    if (!root) return;
    dfs(root->left, v);
    dfs(root->right, v);
    if (!root->left && !root->right) v.push_back(root->val);
  }
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> v1, v2;
    dfs(root1, v1);
    dfs(root2, v2);
    if (v1 == v2) return true;
    return false;
  }
};

int main() {



  return 0;
}