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
  TreeNode* f(vector<int>& preorder, int& i, int max) {
    if (i == preorder.size() || preorder[i] > max) return nullptr;
    TreeNode* node = new TreeNode(preorder[i++]);
    node->left = f(preorder, i, node->val);
    node->right = f(preorder, i, max);
    return node;
  }
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    return f(preorder, i, INT_MAX);
  }
};

int main() {



  return 0;
}