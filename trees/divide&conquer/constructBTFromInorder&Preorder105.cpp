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

  TreeNode* f(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie, unordered_map<int, int>& umap) {
    if (ps > pe || is > ie) return nullptr;
    TreeNode* node = new TreeNode(preorder[ps]);
    int rootPos = umap[preorder[ps]];
    int numsLeft = rootPos - is;
    node->left = f(preorder, ps + 1, ps + numsLeft, inorder, is, rootPos - 1, umap);
    node->right = f(preorder, ps + numsLeft + 1, pe, inorder, rootPos + 1, ie, umap);
    return node;
  }

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    // if(preorder.size()!=inorder.size()) return nullptr; size same given
    int n = inorder.size();
    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++) {
      umap[inorder[i]] = i;
    }
    TreeNode* root = f(preorder, 0, n - 1, inorder, 0, n - 1, umap);
    return root;
  }
};

int main() {



  return 0;
}