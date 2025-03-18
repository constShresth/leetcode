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
  int f(TreeNode* root, unordered_map<TreeNode*, int>& umap) {
    if (!root) return 0;

    if (umap.find(root) != umap.end()) return umap[root];

    int pick = root->val;
    if (root->left) pick = pick + f(root->left->left, umap) + f(root->left->right, umap);
    if (root->right) pick = pick + f(root->right->left, umap) + f(root->right->right, umap);
    int notPick = f(root->left, umap) + f(root->right, umap);

    return umap[root] = max(pick, notPick);
  }
public:
  int rob(TreeNode* root) {
    unordered_map<TreeNode*, int> umap;
    return f(root, umap);
  }
};

int main() {



  return 0;
}