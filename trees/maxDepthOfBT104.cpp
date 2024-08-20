#include <iostream>
#include <queue>
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

int maxDepth(TreeNode* root) {
  //recursive dfs
  if(root==nullptr){
    return 0;
  }
  return 1 + max(maxDepth(root->left),maxDepth(root->right));

  // iterative bfs
  // if(root==nullptr){
  //   return 0;
  // }
  // queue<TreeNode*> q;
  // q.push(root);
  // int depth = 0;
  // while(!q.empty()){
  //   int qSize = q.size();
  //   for(int i=0; i<qSize; i++){
  //     TreeNode* node = q.front();
  //     q.pop();
  //     if(node->left){
  //       q.push(node->left);
  //     }
  //     if(node->right){
  //       q.push(node->right);
  //     }
  //   }
  //   depth++;
  // }
  // return depth;

  // // iterative dfs
  // stack<pair<TreeNode*, int>> st;
  // st.push({root, 1});
  // int depth = 0;
  // while(!st.empty()){
  //   auto [node, currDepth] = st.top();
  //   st.pop();
  //   if(node){
  //     depth = max(depth,currDepth);
  //     st.push({node->left, currDepth+1});
  //     st.push({node->right, currDepth+1});
  //   }
  // }
  // return depth;
}

int main(){

  

  return 0;
}