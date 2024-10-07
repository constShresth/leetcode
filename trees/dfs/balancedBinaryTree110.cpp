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
  void dfs(pair<TreeNode*, int> pair, int& height) {
    if (!pair.first) return;
    int currHeight = pair.second + 1;
    height = max(height, currHeight);
    dfs(make_pair(pair.first->left, currHeight), height);
    dfs(make_pair(pair.first->right, currHeight), height);
  }

  bool flag = true;

  int findHeight(TreeNode* root) {
    if (!root) return 0;

    int lh = findHeight(root->left);
    int rh = findHeight(root->right);

    if (abs(lh - rh) > 1) flag = false;

    return max(lh, rh) + 1;
  }

  bool isBalanced(TreeNode* root) {
    findHeight(root);
    return flag;
    // if(!root) return true;
    // int hleft = 0;
    // int hright = 0;
    // dfs(make_pair(root->left, 0), hleft);
    // dfs(make_pair(root->right, 0), hright);
    // if(abs(hleft-hright)>1) return false;
    // return isBalanced(root->left) && isBalanced(root->right);
    // return true;
  }
};

int main() {



  return 0;
}