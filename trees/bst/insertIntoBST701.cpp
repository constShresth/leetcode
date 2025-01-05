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
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* newNode = new TreeNode(val);
    if (!root) return newNode;
    TreeNode* node = root;
    TreeNode* prev = node;
    while (node) {
      prev = node;
      if (val > node->val) {
        node = node->right;
      }
      else {
        node = node->left;
      }
    }
    if (val > prev->val) prev->right = newNode;
    else prev->left = newNode;
    return root;
    // o(logn)
  }
};

int main() {



  return 0;
}