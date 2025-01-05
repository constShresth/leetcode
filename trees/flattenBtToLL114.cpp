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
  void f(TreeNode* root, TreeNode*& prev) {
    if (!root) return;

    f(root->right, prev);
    f(root->left, prev);

    root->right = prev;
    root->left = nullptr;

    prev = root;
    // o(n),o(n)
  }
  void flatten(TreeNode* root) {
    // TreeNode* prev = NULL;
    // f(root,prev);
    TreeNode* cur = root;
    while (cur != nullptr) {
      if (cur->left != nullptr) {
        TreeNode* node = cur->left;
        while (node->right) node = node->right;
        node->right = cur->right;
        cur->right = cur->left;
        cur->left = nullptr;
      }
      cur = cur->right;
      // o(n), o(1)
    }

    // if(!root) return;

    // stack<TreeNode*> st;
    // st.push(root);
    // while(!st.empty()){
    //     TreeNode* node = st.top(); st.pop();

    //     if(node->right) st.push(node->right);
    //     if(node->left) st.push(node->left);

    //     if(!st.empty()) node->right = st.top();
    //     node->left = nullptr;
    // }
    // o(n), o(n)
  }
};

int main() {



  return 0;
}