#include <iostream>
#include <vector>
#include <queue>
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
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> vec;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int qSize = q.size();
      double avg = 0;
      for (int i = 0;i < qSize;i++) {
        TreeNode* node = q.front();
        q.pop();
        avg += node->val;
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      avg /= qSize;
      vec.push_back(avg);
    }
    return vec;
  }
};

int main() {



  return 0;
}