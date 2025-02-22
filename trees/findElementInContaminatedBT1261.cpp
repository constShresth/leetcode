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

class FindElements {
private:
  void dfs(TreeNode* root) {
    if (!root) return;
    if (root->left) {
      root->left->val = 2 * root->val + 1;
      umap[2 * root->val + 1]++;
      dfs(root->left);
    }
    if (root->right) {
      root->right->val = 2 * root->val + 2;
      umap[2 * root->val + 2]++;
      dfs(root->right);
    }
  }
public:
  unordered_map<int, int> umap;
  FindElements(TreeNode* root) {
    if (!root) return;
    root->val = 0;
    umap[0]++;
    dfs(root);
  }

  bool find(int target) {
    if (umap[target] >= 1) return true;
    return false;
  }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

int main() {



  return 0;
}