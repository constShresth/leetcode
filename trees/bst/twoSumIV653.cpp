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

class BSTIterator {
private:
  stack<TreeNode*> st;
  bool reverse;
  void pushAll(TreeNode* node) {
    while (node) {
      st.push(node);
      if (reverse) node = node->right;
      else node = node->left;
    }
  }
public:
  BSTIterator(TreeNode* root, bool isReverse) {
    reverse = isReverse;
    pushAll(root);
  }

  int next() {
    TreeNode* top = st.top();
    st.pop();
    if (reverse) pushAll(top->left);
    else pushAll(top->right);
    return top->val;
  }

  bool hasNext() {
    return !st.empty();
  }


};
class Solution {
public:
  bool findTarget(TreeNode* root, int k) {
    if (!root) return false;
    BSTIterator l(root, false);
    BSTIterator r(root, true);
    int i = l.next();
    int j = r.next();
    while (i < j) {
      if (i + j == k) return true;
      else if (i + j < k) i = l.next();
      else j = r.next();
    }
    return false;
    // o(n), o(h)
  }
};

int main() {



  return 0;
}