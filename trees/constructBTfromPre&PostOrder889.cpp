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
  TreeNode* construct(int l1, int r1, int l2, int r2, vector<int>& preorder, vector<int>& postorder, unordered_map<int, int>& umap, int n) {
    if (l1 > r1 || l2 > r2) return nullptr;
    TreeNode* root = new TreeNode(preorder[l1]);


    if (l1 == r1) return root;
    int i = umap[preorder[l1 + 1]];
    int size = i - l2 + 1;

    root->left = construct(l1 + 1, l1 + size, l2, i, preorder, postorder, umap, n);
    root->right = construct(l1 + size + 1, r1, i + 1, r2 - 1, preorder, postorder, umap, n);

    return root;
  }
public:
  TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    int n = preorder.size();
    int l = 0;
    int r = n - 1;
    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++) {
      umap[postorder[i]] = i;
    }
    return construct(l, r, l, r, preorder, postorder, umap, n);
  }
};

int main() {



  return 0;
}