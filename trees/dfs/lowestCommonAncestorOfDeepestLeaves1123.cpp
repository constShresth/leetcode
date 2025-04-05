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
private:
  pair<TreeNode*, int> dfs(TreeNode* root) {
    if (root == nullptr) return { nullptr,0 };

    auto [leftNode, leftHeight] = dfs(root->left);
    auto [rightNode, rightHeight] = dfs(root->right);

    if (leftHeight == rightHeight) return { root,leftHeight + 1 };
    else if (leftHeight > rightHeight) return { leftNode, leftHeight + 1 };
    else return { rightNode, rightHeight + 1 };
  }
public:
  TreeNode* lcaDeepestLeaves(TreeNode* root) {
    pair<TreeNode*, int> res = dfs(root);
    return res.first;
  }
};

int main() {



  return 0;
}