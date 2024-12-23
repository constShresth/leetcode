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
  int findSum(TreeNode* root, int& maxi) {
    if (!root) return 0;

    int ls = max(0, findSum(root->left, maxi));
    int rs = max(0, findSum(root->right, maxi));

    maxi = max(maxi, root->val + ls + rs);

    return root->val + max(ls, rs);
  }
  int maxPathSum(TreeNode* root) {
    int maxi = INT_MIN;
    findSum(root, maxi);
    return maxi;
  }
};

int main() {



  return 0;
}