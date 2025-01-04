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
  void preOrder(TreeNode* root, vector<int>& result) {
    // can cause stack overflow for deep trees
    if (!root) return;
    result.push_back(root->val);
    preOrder(root->left, result);
    preOrder(root->right, result);
  }
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    // TreeNode* cur = root;
    while (root != nullptr) {
      if (root->left == nullptr) {
        res.push_back(root->val);
        root = root->right;
      }
      else {
        TreeNode* cur = root->left;
        while (cur->right && cur->right != root) {
          cur = cur->right;
        }
        if (cur->right == nullptr) {
          cur->right = root;
          res.push_back(root->val);
          root = root->left;
        }
        else {
          cur->right = nullptr;
          root = root->right;
        }
      }
    }
    // morris traversal -> o(n), o(1)
    return res;

    // vector<int> result;
    // preOrder(root, result);
    // return result;

    // vector<int> result;
    // if(!root) return result;
    // stack<TreeNode*> st;
    // st.push(root);
    // //doesn't cause stack overflow if the tree is too deep
    // while(!st.empty()){
    //     TreeNode* root = st.top();
    //     st.pop();
    //     result.push_back(root->val);
    //     if(root->right) st.push(root->right);
    //     if(root->left) st.push(root->left);
    // }
    // return result;
  }
};

int main() {



  return 0;
}