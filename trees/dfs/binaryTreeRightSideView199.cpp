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
  void f(TreeNode* root, int level, vector<int>& res) {
    if (!root) return;
    if (level == res.size()) res.push_back(root->val);
    f(root->right, level + 1, res);
    f(root->left, level + 1, res);
  }
  vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    f(root, 0, res);
    return res;
    // o(n),o(h)

    // vector<int> res;
    // if(!root) return res;
    // queue<pair<TreeNode*,int>> q;
    // map<int,int> m;
    // q.push({root,0});
    // while(!q.empty()){
    //     auto p = q.front();
    //     q.pop();
    //     TreeNode* node = p.first;
    //     int x = p.second;
    //     m[x] = node->val;
    //     if(node->left) q.push({node->left,x+1});
    //     if(node->right) q.push({node->right,x+1});
    // }
    // for(auto p:m){
    //     res.push_back(p.second);
    // }
    // return res;
    // o(n),o(n)
  }
};

int main() {



  return 0;
}