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
  TreeNode* recoverFromPreorder(string traversal) {
    int n = traversal.size();
    stack<TreeNode*> st;
    int i = 0;

    while (i < n) {
      int depth = 0;
      while (i < n && traversal[i] == '-') {
        depth++;
        i++;
      }

      int num = 0;
      while (i < n && traversal[i] != '-') {
        num = num * 10 + (traversal[i] - '0');
        i++;
      }

      TreeNode* node = new TreeNode(num);
      if (st.size() == depth) {

      }
      if (!st.empty()) {

        while (st.size() != depth) st.pop();

        TreeNode* root = st.top();

        if (root->left) {
          root->right = node;
        }
        else {
          root->left = node;
        }
      }
      st.push(node);
    }

    while (st.size() > 1) st.pop();
    return st.top();
  }
};

int main() {



  return 0;
}