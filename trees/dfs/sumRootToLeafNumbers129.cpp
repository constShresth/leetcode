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
  void f(TreeNode* root, int sum, int& totalSum) {
    sum = sum * 10 + root->val;
    if (!root->left && !root->right) {
      totalSum += sum;
      return;
    }
    if (root->left) f(root->left, sum, totalSum);
    if (root->right) f(root->right, sum, totalSum);
  }
  int sumNumbers(TreeNode* root) {
    vector<int> path;
    int sum = 0;
    int totalSum = 0;
    f(root, sum, totalSum);
    return totalSum;
    // o(n),o(h)
  }
};

int main() {



  return 0;
}