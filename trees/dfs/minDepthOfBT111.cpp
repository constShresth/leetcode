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
  int findDepth(TreeNode* root) {
    if (!root) return 0;

    int lDepth = findDepth(root->left);
    int rDepth = findDepth(root->right);
    if (!lDepth || !rDepth) return max(lDepth, rDepth) + 1;
    else return min(lDepth, rDepth) + 1;
  }

  int minDepth(TreeNode* root) {
    return findDepth(root);
  }
};

int main() {



  return 0;
}