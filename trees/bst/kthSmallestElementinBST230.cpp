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
  int kthSmallest(TreeNode* root, int k) {
    // inorder traversal of bst is sorted
    vector<int> inorder;
    while (root) {
      if (!root->left) {
        inorder.push_back(root->val);
        root = root->right;
      }
      else {
        TreeNode* node = root->left;
        while (node->right && node->right != root) {
          node = node->right;
        }
        if (!node->right) {
          node->right = root;
          root = root->left;
        }
        else {
          node->right = nullptr;
          inorder.push_back(root->val);
          root = root->right;
        }
      }
    }
    // morris traversal -> o(n), o(1)
    return inorder[k - 1];
  }
};

int main() {



  return 0;
}