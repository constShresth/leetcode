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
  void dfs(TreeNode* root, vector<int>& res) {
    // can cause stack overflow for deep trees
    if (!root) return;
    dfs(root->left, res);
    res.push_back(root->val);
    dfs(root->right, res);
  }
  vector<int> inorderTraversal(TreeNode* root) {

    vector<int> inorder;
    TreeNode* cur = root;
    while (cur != NULL) {
      if (cur->left == NULL) {
        inorder.push_back(cur->val);
        cur = cur->right;
      }
      else {
        TreeNode* node = cur->left;
        while (node->right && node->right != cur) {
          node = node->right;
        }

        if (node->right == NULL) {
          node->right = cur;
          cur = cur->left;
        }
        else {
          node->right = NULL;
          inorder.push_back(cur->val);
          cur = cur->right;
        }
      }
    }
    //Morris traversal -> o(n), o(1)
    return inorder;

    // vector<int> res;
    // dfs(root, res);
    // return res;

    // vector<int> res;
    // if(!root) return res;
    // stack<TreeNode*> st;
    // TreeNode* node = root;
    // while(true){
    //     if(node){
    //         st.push(node);
    //         node = node->left;
    //     }else{
    //         if(st.empty()) break;
    //         node = st.top();
    //         st.pop();
    //         res.push_back(node->val);
    //         node = node->right;
    //     }
    // }
    // return res;

  }
};

int main() {



  return 0;
}