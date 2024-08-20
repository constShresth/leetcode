#include <iostream>
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
  void dfs(TreeNode* root, TreeNode*& prev, int& result) {
    if (!root) return;
    dfs(root->left, prev, result);
    if (prev) result = min(result, abs(root->val - prev->val));
    prev = root;
    dfs(root->right, prev, result);
  }
  int getMinimumDifference(TreeNode* root) {
    //we can iterate through bst in sorted order with in-order traversal
    int result = INT_MAX;
    TreeNode* prev = nullptr;
    dfs(root, prev, result);
    return result;
  }
};

int main() {



  return 0;
}