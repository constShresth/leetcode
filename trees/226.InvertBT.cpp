#include <iostream>
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
  TreeNode* invertTree(TreeNode* root) {
    if(root==nullptr) return root;
    TreeNode* curr = root;
    if(curr->left!=nullptr && curr->right!=nullptr){
      TreeNode* temp = curr->left;
      curr->left = curr->right;
      curr->right = temp;
    }else if(curr->left){
      curr->right = curr->left;
      curr->left = nullptr;
    }else{
      curr->left = curr->right;
      curr->right = nullptr;
    }
    
    invertTree(curr->left);
    invertTree(curr->right);
    return root;
  }
};

int main(){

  

  return 0;
}