#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if(!root) return false;
    stack<pair<TreeNode*,int>> s;
    s.push({root,root->val});
    while(!s.empty()){
      auto [node, sum] = s.top();
      s.pop();
      if(node){
        if(sum==targetSum && !node->left && !node->right) return true;
        if(node->left){
          s.push({node->left,sum+node->left->val});
        }
        if(node->right){
          s.push({node->right,sum+node->right->val});
        }
      }
    }
    return false;
  }
};

int main(){

  

  return 0;
}