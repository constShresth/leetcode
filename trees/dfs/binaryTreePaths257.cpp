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
  void f(TreeNode* root, vector<string>& res, string s) {
    s.append(to_string(root->val));
    if (!root->left && !root->right) res.push_back(s);
    s.append("->");
    if (root->left) f(root->left, res, s);
    if (root->right) f(root->right, res, s);
  }
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    string s;
    f(root, res, s);
    return res;
  }
};

int main() {



  return 0;
}