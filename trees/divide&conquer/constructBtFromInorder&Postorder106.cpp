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
  TreeNode* f(vector<int>& inorder, int is, int ie, vector<int>& postorder,
    int ps, int pe, unordered_map<int, int>& umap) {
    if (ps > pe || is > ie) return nullptr;
    TreeNode* node = new TreeNode(postorder[pe]);
    int rootPos = umap[postorder[pe]];
    int numsLeft = rootPos - is;
    node->left = f(inorder, is, rootPos - 1, postorder, ps, ps + numsLeft - 1, umap);
    node->right = f(inorder, rootPos + 1, ie, postorder, ps + numsLeft, pe - 1, umap);
    return node;
  }
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++) {
      umap[inorder[i]] = i;
    }
    TreeNode* root = f(inorder, 0, n - 1, postorder, 0, n - 1, umap);
    return root;
  }
};

int main() {



  return 0;
}