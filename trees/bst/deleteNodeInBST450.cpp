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
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;
    if (key < root->val) root->left = deleteNode(root->left, key);
    else if (key > root->val) root->right = deleteNode(root->right, key);
    else {
      if (!root->left) return root->right;
      else if (!root->right) return root->left;
      TreeNode* curr = root->right;
      while (curr->left) {
        curr = curr->left;
      }
      // curr->left = root->left;
      // return root->right;
      root->val = curr->val;
      root->right = deleteNode(root->right, curr->val);
    }
    return root;
  }
};

int main() {



  return 0;
}