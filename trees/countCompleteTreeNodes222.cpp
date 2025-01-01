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
  int findLeftHeight(TreeNode* node) {
    int height = 0;
    while (node) {
      height++;
      node = node->left;
    }
    return height;
  }
  int findRightHeight(TreeNode* node) {
    int height = 0;
    while (node) {
      height++;
      node = node->right;
    }
    return height;
  }
  int countNodes(TreeNode* root) {
    if (!root) return 0;
    int lh = findLeftHeight(root); //o(log(n))
    int rh = findRightHeight(root);
    if (lh == rh) return (1 << lh) - 1; // 2^lh - 1
    return 1 + countNodes(root->left) + countNodes(root->right);
    // o((log(n))^2), o(h)
    // h = log(n) worst case since complete tree
  }
};

int main() {



  return 0;
}